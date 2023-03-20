#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<string>;


using namespace cv; 

int main_camera(std::string ip);
int sur_camera(std::string ip);


int main()
{
	int button;
	std::cin >> button;


	switch (button)
	{
	case 1:
		main_camera("rtsp://192.168.31.86:554/ch01.264");

		break;
	case 2:
		sur_camera("rtsp://192.168.31.86:554/ch01_sub.264");

		break;

	}

}

int main_camera(std::string ip)
{
	VideoCapture cap;
	cap.open(ip);

	if (!cap.isOpened())
	{
		std::cout << "error 0" << std::endl;
		return -1;
	}

	namedWindow("main",250);

	Mat frame;

	while (true)
	{
		bool s = cap.read(frame);

		if (!s)
		{
			std::cout << "error 1" << std::endl;
		}

		imshow("main", frame);
		if (waitKey(1) == 27)
		{
			std::cout << "perfect" << std::endl;
			break;
		}
	}


	return 0;
}

int sur_camera(std::string ip)
{
	VideoCapture cap;
	cap.open(ip);

	if (!cap.isOpened())
	{
		std::cout << "error 0" << std::endl;
		return -1;
	}

	namedWindow("sur", 250);

	Mat frame;

	while (true)
	{
		bool s = cap.read(frame);

		if (!s)
		{
			std::cout << "error 1" << std::endl;
		}

		imshow("sur", frame);
		if (waitKey(1) == 27)
		{
			std::cout << "perfect" << std::endl;
			break;
		}
	}


	return 0;
}


/*
//rtsp://192.168.31.86:554/ch01.264
//rtsp://192.168.31.86:554/ch01_sub.264
*/

/*
opencv_video — анализ движения и отслеживание объектов (оптический поток, шаблоны движения, устранение фона).
*/