namespace db
{
void imshow(const cv::String &winName_, const cv::Mat &img_)
{
#ifdef DEBUG
    if (img_.depth() == CV_8U)
    {
        cv::imshow(winName_, img_);
    }
    else
    {
        double min_ = 0, max_ = 0;
        cv::Point2i min_pt, max_pt;
        cv::Mat temp;
        cv::minMaxLoc(img_, &min_, &max_, &min_pt, &max_pt, cv::noArray());
        cv::normalize(img_, temp, 0, 255, cv::NORM_MINMAX, CV_8U, {});

        cv::imshow(winName_, temp);
        if (min_ < 0 || max_ > 1)
        {
            fmt::print("[DEBUG] {} is not of any showing formats, a makeshift image "
                       "is create.\nOriginal states:\n",
                       winName_);
            fmt::print("minVal: {} at point ({},{})\n", min_, min_pt.x, min_pt.y);
            fmt::print("maxVal: {} at point ({},{})\n\n", max_, max_pt.x, max_pt.y);
        }
    }
#endif // DEBUG
}

void draw_rotatedRect(InputOutputArray image, const RotatedRect& rt)
{
    cv::Scalar color = cv::Scalar(255.0, 0.0, 255.0); // white
    cv::Point2f vertices2f[4];
    rt.points(vertices2f);
    cv::Point vertices[4];
    for(int i = 0; i < 4; ++i){
        vertices[i] = vertices2f[i];
    }
    cv::fillConvexPoly(image, vertices, 4, color);
}
}; // namespace db