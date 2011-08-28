#pragma once

#include "ofxCv.h"

/*
 the contour finder is with automatically threshold your image for you. it will
 also convert non-grayscale images to grayscale before thresholding. if you
 want to disable this, setAutoThreshold(false). by default the threshold is
 128. to change this, use setThreshold().
 */

// to implement in ContourFinder:
// cv::contourArea and filtering
// holes/no holes
// cv::boundingRect
// CV_THRESH_OTSU?
// cv::arcLength
// cv::convexHull
// cv::minAreaRect
// cv::fitEllipse
// cv::pointPolygonTest

// cv::matchShapes?
// cv::estimateRigidTransform? subdivision-based estimation for outline-flow?

namespace ofxCv {
	
	class ContourFinder {
	public:
		ContourFinder();
		
		template <class T> 
		void findContours(T& img) {
			findContours(toCv(img));
		}
		void findContours(cv::Mat img);
		vector<vector<cv::Point> >& getContours();
		vector<ofPolyline>& getPolylines();
		
		void setAutoThreshold(bool autoThreshold);
		void setThreshold(float thresholdValue);
		void setInvert(bool invert);
		
		void setSimplify(bool simplify);
		
		void draw();
	protected:
		cv::Mat thresh;
		bool autoThreshold, invert, simplify;
		float thresholdValue;
		vector<vector<cv::Point> > contours;
		vector<ofPolyline> polylines;
	};	
}