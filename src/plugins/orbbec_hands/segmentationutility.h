#ifndef SEGMENTATIONTRACKER_H
#define SEGMENTATIONTRACKER_H

#include <opencv2/opencv.hpp>

struct TrackingData;

class SegmentationUtility
{
public:
    static cv::Point convergeTrackPointFromSeed(TrackingData data);

    static void calculateSegmentArea(cv::Mat& matDepth, cv::Mat& matArea, const float resizeFactor);
    static void calculateEdgeDistance(cv::Mat& matSegmentation, cv::Mat& matArea, cv::Mat& matEdgeDistance);

    static void calculateBasicScore(cv::Mat& matDepth, cv::Mat& matScore, const float heightFactor, const float depthFactor, const float resizeFactor);

    static bool findForegroundPixel(cv::Mat& matForeground, cv::Point& foregroundPosition);

private:
    static void segmentForeground(TrackingData data);
    static cv::Point trackPointFromSeed(TrackingData data);

    static float getDepthArea(cv::Point3f& p1, cv::Point3f& p2, cv::Point3f& p3, const float resizeFactor);

};

#endif // SEGMENTATIONTRACKER_H