#pragma once

#include <opencv2/opencv.hpp>
using namespace cv;

#define CV_VERSION_NUMBER CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)


#ifdef _DEBUG
#pragma comment(lib, "opencv_viz"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_videostab"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_video"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_ts"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_superres"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_stitching"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_photo"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_ocl"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_objdetect"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_nonfree"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_ml"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_legacy"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_imgproc"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_highgui"CV_VERSION_NUMBER"d.lib")
//#pragma comment(lib, "opencv_haartraining_engine.lib")
#pragma comment(lib, "opencv_gpu"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_flann"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_features2d"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_core"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_contrib"CV_VERSION_NUMBER"d.lib")
#pragma comment(lib, "opencv_calib3d"CV_VERSION_NUMBER"d.lib")
#else
#pragma comment(lib, "opencv_viz"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_videostab"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_video"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_ts"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_superres"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_stitching"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_photo"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_ocl"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_objdetect"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_nonfree"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_ml"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_legacy"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_imgproc"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_highgui"CV_VERSION_NUMBER".lib")
//#pragma comment(lib, "opencv_haartraining_engine.lib")
#pragma comment(lib, "opencv_gpu"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_flann"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_features2d"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_core"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_contrib"CV_VERSION_NUMBER".lib")
#pragma comment(lib, "opencv_calib3d"CV_VERSION_NUMBER".lib")
#endif

//Draw fuction

//merge two images into one image with some options.
void patchBlendImage(Mat& src1, Mat& src2, Mat& dest, Scalar linecolor=CV_RGB(0,0,0), int linewidth = 2, int direction = 0);

void alphaBlend(const Mat& src1, const Mat& src2, const Mat& alpha, Mat& dest);
void alphaBlend(const Mat& src1, const Mat& src2, double alpha, Mat& dest);
void guiAlphaBlend(const Mat& src1, const Mat& src2);

void eraseBoundary(const Mat& src, Mat& dest, int step, int border=BORDER_REPLICATE);

//sse utils
void memcpy_float_sse(float* dest, float* src, const int size);

// utility functions
void showMatInfo(InputArray src_, string name="Mat");
double YPSNR(const Mat& src1, const Mat& src2);


void guiCompareDiff(Mat& before, Mat& after, Mat& ref);
void guiAbsDiffCompareNE(Mat& src1, Mat& src2);
void guiAbsDiffCompareEQ(Mat& src1, Mat& src2);
void guiAbsDiffCompareLE(Mat& src1, Mat& src2);
void guiAbsDiffCompareGE(Mat& src1, Mat& src2);

class ConsoleImage
{
private:
	int count;
	string windowName;
	std::vector<std::string> strings;
	bool isLineNumber;
public:
	void setIsLineNumber(bool isLine = true);
	bool getIsLineNumber();
	cv::Mat show;

	void init(Size size, string wname);
	ConsoleImage();
	ConsoleImage(cv::Size size, string wname = "console");
	~ConsoleImage();

	void printData();
	void clear();

	void operator()(string src);
	void operator()(const char *format, ...);
	void operator()(cv::Scalar color, const char *format, ...);

	void flush(bool isClear=true);
};



enum
{
	TIME_AUTO=0,
	TIME_NSEC,
	TIME_MSEC,
	TIME_SEC,
	TIME_MIN,
	TIME_HOUR,
	TIME_DAY
};
class CalcTime
{
	int64 pre;
	string mes;

	int timeMode;

	double cTime;
	bool _isShow;

	int autoMode;
	int autoTimeMode();
	vector<string> lap_mes;
public:
	
	void start();
	void setMode(int mode);
	void setMessage(string src);
	void restart();
	double getTime();
	void show();
	void show(string message);
	void lap(string message);
	void init(string message, int mode, bool isShow);

	CalcTime(string message, int mode=TIME_AUTO, bool isShow=true);
	CalcTime();

	~CalcTime();
};

class Stat 
{
public:
	Vector<double> data;
	int num_data;
	Stat();
	~Stat();
	double getMin();
	double getMax();
	double getMean();
	double getStd();
	double getMedian();

	void push_back(double val);

	void clear();
	void show();
};

void addNoise(Mat&src, Mat& dest, double sigma, double solt_papper_rate=0.0);

//image processing
void print_m128(__m128d src);
void print_m128(__m128 src);
void print_m128i_char(__m128i src);
void print_m128i_uchar(__m128i src);
void print_m128i_short(__m128i src);
void print_m128i_ushort(__m128i src);
void print_m128i_int(__m128i src);
void print_m128i_uint(__m128i src);

//arithmetics
void pow_fmath(const float a  , const Mat&  src , Mat & dest);
void pow_fmath(const Mat& src , const float a   , Mat & dest);
void pow_fmath(const Mat& src1, const Mat&  src2, Mat & dest);

//bit convert
void cvt32f8u(const Mat& src, Mat& dest);
void cvt8u32f(const Mat& src, Mat& dest, const float amp);
void cvt8u32f(const Mat& src, Mat& dest);

//convert a BGR color image into a continued one channel data: ex BGRBGRBGR... -> BBBB...(image size), GGGG....(image size), RRRR....(image size).
void cvtColorBGR2PLANE(const Mat& src, Mat& dest);
void cvtColorPLANE2BGR(const Mat& src, Mat& dest);

void cvtColorBGRA2BGR(const Mat& src, Mat& dest);
void cvtColorBGRA32f2BGR8u(const Mat& src, Mat& dest);

void cvtColorBGR2BGRA(const Mat& src, Mat& dest, const uchar alpha=255);
void cvtColorBGR8u2BGRA32f(const Mat& src, Mat& dest, const float alpha=255.f);


//convert a BGR color image into a skipped one channel data: ex BGRBGRBGR... -> BBBB...(cols size), GGGG....(cols size), RRRR....(cols size),BBBB...(cols size), GGGG....(cols size), RRRR....(cols size),...
void splitBGRLineInterleave( const Mat& src, Mat& dest);

void mergeHorizon(const vector<Mat>& src, Mat& dest);
void splitHorizon(const Mat& src, vector<Mat>& dest, int num);
//split by number of grid
void mergeFromGrid(Vector<Mat>& src, Size beforeSize, Mat& dest, Size grid, int borderRadius);
void splitToGrid(const Mat& src, Vector<Mat>& dest, Size grid, int borderRadius);

//slic
void SLIC(const Mat& src, Mat& segment, int regionSize, float regularization, float minRegionRatio, int max_iteration);
void drawSLIC(const Mat& src, Mat& segment, Mat& dest, bool isLine=true, Scalar line_color=Scalar(0,0,255));
void SLICBase(Mat& src, Mat& segment, int regionSize, float regularization, float minRegionRatio, int max_iteration);


void maxFilter(const Mat& src, Mat& dest, Size kernelSize);
void maxFilter(const Mat& src, Mat& dest, int radius);
void minFilter(const Mat& src, Mat& dest, Size kernelSize);
void minFilter(const Mat& src, Mat& dest, int radius);


enum
{
	FILTER_DEFAULT = 0,
	FILTER_CIRCLE,
	FILTER_RECTANGLE,
	FILTER_SEPARABLE,
	FILTER_SLOWEST,// for just comparison.
};

void GaussianFilter(const Mat src, Mat& dest, int r, float sigma, int method=FILTER_SLOWEST, Mat& mask=Mat());
void weightedGaussianFilter(Mat& src, Mat& weight, Mat& dest,Size ksize, float sigma, int border_type = BORDER_REPLICATE);

void jointNearestFilterBase(const Mat& src, const Mat& guide, const Size ksize, Mat& dest);

//bilateral filters
enum
{
	BILATERAL_ORDER2,//underconstruction
	BILATERAL_ORDER2_SEPARABLE//underconstruction
};




void bilateralFilter(const Mat& src, Mat& dst, Size kernelSize, double sigma_color, double sigma_space, int method=FILTER_DEFAULT, int borderType=cv::BORDER_REPLICATE);
void jointBilateralFilter(const Mat& src, const Mat& guide, Mat& dst, Size kernelSize, double sigma_color, double sigma_space, int method=FILTER_DEFAULT, int borderType=cv::BORDER_REPLICATE);

void weightedBilateralFilter(const Mat& src, Mat& weight, Mat& dst, Size kernelSize, double sigma_color, double sigma_space, int method, int borderType=cv::BORDER_REPLICATE);
void weightedJointBilateralFilter(const Mat& src, Mat& weightMap,const Mat& guide, Mat& dst, Size kernelSize, double sigma_color, double sigma_space, int method, int borderType);

void guidedFilter(const Mat& src,  Mat& dest, const int radius,const float eps);
void guidedFilter(const Mat& src, const Mat& guidance, Mat& dest, const int radius,const float eps);

void guidedFilterMultiCore(const Mat& src, Mat& dest, int r,float eps, int numcore=0);
void guidedFilterMultiCore(const Mat& src, const Mat& guide, Mat& dest, int r,float eps,int numcore=0);


typedef enum
{
	DTF_L1=1,
	DTF_L2=2
}DTF_NORM;

typedef enum
{
	DTF_RF=0,//Recursive Filtering
	DTF_NC=1,//Normalized Convolution
	DTF_IC=1,//Interpolated Convolution

}DTF_METHOD;

typedef enum
{
	DTF_BGRA_SSE=0,
	DTF_BGRA_SSE_PARALLEL,
	DTF_SLOWEST
}DTF_IMPLEMENTATION;

void domainTransformFilterRF(const Mat& img, Mat& out, float sigma_r, float sigma_s, int maxiter, int norm=DTF_L1, int implementation=DTF_BGRA_SSE_PARALLEL);
void domainTransformFilterRF(const Mat& img, const Mat& guide, Mat& out, float sigma_r, float sigma_s,int maxiter, int norm=DTF_L1, int implementation=DTF_BGRA_SSE_PARALLEL);

class DomainTransformFilter
{
	Mat img;
	Mat guidef;
	Mat dctx;
	Mat dcty;

public:
	DomainTransformFilter();
	void operator()(const Mat& src, const Mat& guide, Mat& dest, float sigma_r, float sigma_s, int maxiter, int norm);
};



void recursiveBilateralFilter(Mat& src, Mat& dest, float sigma_range, float sigma_spatial, int method=0);
class RecursiveBilateralFilter
{
private:
	Mat bgra;

	Mat texture;//texture is joint signal
	Mat destf; 
	Mat temp; 
	Mat tempw;

	Size size;
public:
	void setColorLUTGaussian(float* lut, float sigma);
	void setColorLUTLaplacian(float* lut, float sigma);
	void init(Size size_);
	RecursiveBilateralFilter(Size size);
	RecursiveBilateralFilter();
	~RecursiveBilateralFilter();
	void operator()(const Mat& src, Mat& dest, float sigma_range, float sigma_spatial);
	void operator()(const Mat& src, const Mat& guide, Mat& dest, float sigma_range, float sigma_spatial);
};


void binalyWeightedRangeFilter(const Mat& src, Mat& dst, Size kernelSize, float threshold, int method=FILTER_DEFAULT, int borderType=cv::BORDER_REPLICATE);
void jointBinalyWeightedRangeFilter(const Mat& src, const Mat& guide, Mat& dst, Size kernelSize, float threshold, int method=FILTER_DEFAULT, int borderType=cv::BORDER_REPLICATE);

void nonLocalMeansFilter(Mat& src, Mat& dest, int templeteWindowSize, int searchWindowSize, double h, double sigma=-1.0, int method=FILTER_DEFAULT);

void iterativeBackProjectionDeblurGaussian(const Mat& src, Mat& dest, const Size ksize, const double sigma, const double lambda, const int iteration);
void iterativeBackProjectionDeblurBilateral(const Mat& src, Mat& dest, const Size ksize, const double sigma_color, const double sigma_space, const double lambda, const int iteration);

enum
{
	PROCESS_LAB=0,
	PROCESS_BGR
};

void detailEnhancementBilateral(Mat& src, Mat& dest, int d, float sigma_color, float sigma_space, float boost, int color=PROCESS_LAB);



void fillOcclusion(Mat& src, int invalidvalue=0);// for disparity map

class dispRefinement
{
private:

public:

	int r;
	int th;
	int iter_ex;
	int th_r;
	int r_flip;
	int iter;
	int iter_g;
	int r_g;
	int eps_g;
	int th_FB;

	dispRefinement();
	void boundaryDetect(Mat& src, Mat& guid, Mat& dest, Mat& mask);
	void dispRefine(Mat& src, Mat& guid, Mat& guid_mask, Mat& alpha);
	void operator()(Mat& src, Mat& guid, Mat& dest);
};

class mattingMethod
{
private:
	Mat trimap;
	Mat trimask;
	Mat f;
	Mat b;
	Mat a;

public:

	int r;
	int iter;
	int iter_g;
	int r_g;
	int eps_g;
	int th_FB;
	int r_Wgauss;
	int sigma_Wgauss;
	int th;

	mattingMethod();
	void boundaryDetect(Mat& disp);
	void getAmap(Mat& img);
	void getFBimg(Mat& img);
	void operator()(Mat& img, Mat& disp, Mat& alpha, Mat& Fimg, Mat& Bimg);
};

class StereoViewSynthesis
{
private:
	void depthfilter(Mat& depth, Mat& depth2,Mat& mask2,int viewstep,double disp_amp);
	template <class T>
	void analyzeSynthesizedViewDetail_(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, double alpha, int invalidvalue, double disp_amp,Mat& srcsynth, Mat& ref);
	template <class T>
	void viewsynth (const Mat& srcL, const Mat& srcR, const Mat& dispL, const Mat& dispR, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp, int disptype);
	template <class T>
	void makeMask_(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, double alpha, int invalidvalue, double disp_amp);
	template <class T>
	void viewsynthSingle(Mat& src,Mat& disp, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp, int disptype);
public:
	//warping parameters
	enum 
	{
		WAPR_IMG_INV= 0,//Mori et al.
		WAPR_IMG_FWD_SUB_INV, //Zenger et al.
	};
	int warpMethod;

	int warpInterpolationMethod;//Nearest, Linear or Cubic
	bool warpSputtering;
	int large_jump;

	//warped depth filtering parameters
	enum 
	{
		DEPTH_FILTER_SPECKLE = 0,
		DEPTH_FILTER_MEDIAN,
		DEPTH_FILTER_MEDIAN_ERODE,
		DEPTH_FILTER_CRACK,
		DEPTH_FILTER_MEDIAN_BILATERAL,
		DEPTH_FILTER_NONE
	};
	int depthfiltermode;
	int warpedMedianKernel;

	int warpedSpeckesWindow;
	int warpedSpeckesRange;

	int bilateral_r;
	float bilateral_sigma_space;
	float bilateral_sigma_color;

	//blending parameter

	int blendMethod;
	double blend_z_thresh;

	//post filtering parameters
	enum 
	{
		POST_GAUSSIAN_FILL=0,
		POST_FILL,
		POST_NONE
	};
	int postFilterMethod;

	enum 
	{
	FILL_OCCLUSION_LINE = 0,
	FILL_OCCLUSION_REFLECT = 1,
	FILL_OCCLUSION_STRETCH = -1,
	FILL_OCCLUSION_HV=2,
	FILL_OCCLUSION_INPAINT_NS=3, // OpenCV Navier-Stokes algorithm
	FILL_OCCLUSION_INPAINT_TELEA=4, // OpenCV A. Telea algorithm
	};
	int inpaintMethod;

	double inpaintr;//parameter for opencv inpaint 
	int canny_t1;
	int canny_t2;

	Size occBlurSize;

	Size boundaryKernelSize;
	double boundarySigma;
	double boundaryGaussianRatio;


	//preset
	enum 
	{
	PRESET_FASTEST = 0,
	PRESET_SLOWEST,
	};

	StereoViewSynthesis();
	StereoViewSynthesis(int preset);
	void init(int preset);

	void operator()(Mat& src,Mat& disp, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp);
	void operator()(const Mat& srcL, const Mat& srcR, const Mat& dispL, const Mat& dispR, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp);

	Mat diskMask;
	Mat allMask;//all mask
	Mat boundaryMask;//disparity boundary
	Mat nonOcclusionMask;
	Mat occlusionMask;//half and full occlusion
	Mat fullOcclusionMask;//full occlusion
	Mat nonFullOcclusionMask; //bar of full occlusion
	Mat halfOcclusionMask;//left and right half ooclusion

	void viewsynthSingleAlphaMap(Mat& src,Mat& disp, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp, int disptype);
	void alphaSynth(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp);
	void noFilter(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp);
	void analyzeSynthesizedViewDetail(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, double alpha, int invalidvalue, double disp_amp,Mat& srcsynth, Mat& ref);
	void analyzeSynthesizedView(Mat& srcsynth, Mat& ref);
	void makeMask(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, double alpha, int invalidvalue, double disp_amp);
	void makeMask(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, double alpha, int invalidvalue, double disp_amp, Mat& srcsynth, Mat& ref);

	void check(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR, Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp, Mat& ref);
	void check(Mat& src,Mat& disp,Mat& dest, Mat& destdisp, double alpha, int invalidvalue, double disp_amp, Mat& ref);
	void preview(Mat& srcL,Mat& srcR, Mat& dispL,Mat& dispR,int invalidvalue, double disp_amp);
	void preview(Mat& src, Mat& disp,int invalidvalue, double disp_amp);
};