#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <chrono>

using namespace std;
using namespace cv;
using namespace chrono;


void photo()
{
    auto start = steady_clock::now();

    Mat ip_img = imread("C:/Users/Mustafa/Desktop/opencv_ornekler/u.png");

    Mat c_ip_img = ip_img.clone();

    cvtColor(ip_img, ip_img, COLOR_BGR2GRAY);

    GaussianBlur(ip_img, ip_img, Size(3, 3), 10, 10);

    Canny(ip_img, ip_img, 0, 255);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarcy;
    findContours(ip_img, contours, hierarcy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector<vector<Point>> contours_poly(contours.size());

    int amount = contours.size();
    cout << "contours: " << amount << endl;

    string shapes[] = { "cember","ucgen","kare","dikdortgen","besgen","altigen" ,"yedigen","sekizgen" };

    vector<int> kenar_array;

    string shape_string;
    int area;
    string area_s;
    string kenar;

    RotatedRect text_rect;

    for (int i = 0; i < contours.size(); i++)
    {
        approxPolyDP(Mat(contours[i]), contours_poly[i], 15, true);

        drawContours(c_ip_img, contours_poly, i, Scalar(255, 255, 0), 2, 8);

        int size_contour = contours_poly[i].size();

        if (size_contour > 9) {

            shape_string = shapes[0];
        }

        else if (size_contour == 3) {
            shape_string = shapes[1];
        }
        else if (size_contour == 4) {
            shape_string = shapes[3];
        }
        else if (size_contour == 5) {
            shape_string = shapes[4];
        }
        else if (size_contour == 6) {
            shape_string = shapes[5];
        }
        else if (size_contour == 6) {
            shape_string = shapes[5];
        }
        else if (size_contour == 6) {
            shape_string = shapes[5];
        }
        else if (size_contour == 7) {
            shape_string = shapes[6];
        }
        else if (size_contour == 8) {
            shape_string = shapes[7];
        }

        int j = 0;
        Point2f p_1;
        Point2f p_2;
        int dis;

        while (j < size_contour)
        {
            if (j == size_contour - 1) {

                p_1 = contours_poly[i][j];
                p_2 = contours_poly[i][0];

                dis = norm(Mat(p_1), Mat(p_2));

                Point2i p_off;

                kenar_array.push_back(dis);

                kenar = to_string(dis);
                p_off = (p_1 + p_2) / 2;

                putText(c_ip_img, kenar, p_off, 1, 1, Scalar(255, 0, 0));

            }

            else {
                p_1 = contours_poly[i][j];
                p_2 = contours_poly[i][j + 1];

                dis = norm(Mat(p_1), Mat(p_2));

                Point2i p_off;

                kenar_array.push_back(dis);

                p_off = (p_1 + p_2) / 2;

                kenar = to_string(dis);

                putText(c_ip_img, kenar, p_off, 1, 1, Scalar(255, 0, 0));

            }

            j = j + 1;
        }

        for (int x = 0; x < size_contour; x++) {

            if (x == size_contour - 1) {
                /* float dot = ((contours_poly[i][0]).x - (contours_poly[i][x].x))
                     * ((contours_poly[i][x-1]).x - (contours_poly[i][x].x)) +
                     ((contours_poly[i][0]).y - (contours_poly[i][x].y))
                     * ((contours_poly[i][x-1]).y - (contours_poly[i][x].y));*/
                Point2i dot_1 = (contours_poly[i][0]) - (contours_poly[i][x]);
                Point2i dot_2 = (contours_poly[i][x - 1]) - (contours_poly[i][x]);
                float dot = Mat(dot_1).dot(Mat(dot_2));


                float sonuc = dot / (kenar_array[x - 1] * kenar_array[x]);

                sonuc = 57.295 * acos(sonuc);

                string sonuc_ = to_string(sonuc);
                putText(c_ip_img, sonuc_, contours_poly[i][x], 1, 1, Scalar(255, 0, 0));

            }

            if (x == 0) {
                /*float dot = ((contours_poly[i][x + 1]).x - (contours_poly[i][x].x))
                    * ((contours_poly[i][size_contour - 1]).x - (contours_poly[i][x].x)) +
                    ((contours_poly[i][x + 1]).y - (contours_poly[i][x].y))
                    * ((contours_poly[i][size_contour - 1]).y - (contours_poly[i][x].y));*/


                Point2i dot_1 = (contours_poly[i][x + 1]) - (contours_poly[i][x]);
                Point2i dot_2 = (contours_poly[i][size_contour - 1]) - (contours_poly[i][x]);
                float dot = Mat(dot_1).dot(Mat(dot_2));

                float sonuc = dot / (kenar_array[size_contour - 1] * kenar_array[x]);

                sonuc = 57.295 * acos(sonuc);

                string sonuc_ = to_string(sonuc);
                putText(c_ip_img, sonuc_, contours_poly[i][x], 1, 1, Scalar(255, 0, 0));

            }

            if (x != 0 && x != size_contour - 1) {


                /*float dot = ((contours_poly[i][x + 1]).x - (contours_poly[i][x].x))
                    * ((contours_poly[i][x-1]).x - (contours_poly[i][x].x)) +
                    ((contours_poly[i][x + 1]).y - (contours_poly[i][x].y))
                    * ((contours_poly[i][x - 1]).y - (contours_poly[i][x].y));*/

                Point2i dot_1 = (contours_poly[i][x + 1]) - (contours_poly[i][x]);
                Point2i dot_2 = (contours_poly[i][x - 1]) - (contours_poly[i][x]);
                float dot = Mat(dot_1).dot(Mat(dot_2));

                float sonuc = dot / (kenar_array[x - 1] * kenar_array[x]);

                sonuc = 57.295 * acos(sonuc);

                string sonuc_ = to_string(sonuc);
                putText(c_ip_img, sonuc_, contours_poly[i][x], 1, 1, Scalar(255, 0, 0));

            }

        }
        text_rect = minAreaRect(contours[i]);
        area = contourArea(contours[i]);
        area_s = to_string(area);


        Point2f p(0, 15);
        putText(c_ip_img, shape_string, text_rect.center, 1, 1, Scalar(255, 0, 0));
        putText(c_ip_img, area_s, text_rect.center + p, 1, 1, Scalar(255, 0, 0));
        kenar_array.clear();

    }

    auto end = steady_clock::now();

    double gecen_zaman = double(duration_cast <milliseconds> (end - start).count());

    cout << "time: " << gecen_zaman << "ms" << endl;

    imshow("im", c_ip_img);
    waitKey(0);

}


void cam()
{
    VideoCapture cap(0);
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(cv::CAP_PROP_FRAME_COUNT, 30);
    Mat ip_img;

    if (!cap.isOpened())
    {

        cout << "fail" << endl;
    }

    while (true)
    {

        cap >> ip_img;
        auto start = steady_clock::now();

        Mat c_ip_img = ip_img.clone();

        cvtColor(ip_img, ip_img, COLOR_BGR2GRAY);

        GaussianBlur(ip_img, ip_img, Size(3, 3), 10, 10);

        Canny(ip_img, ip_img, 0, 255);

        vector<vector<Point>> contours;
        vector<Vec4i> hierarcy;
        findContours(ip_img, contours, hierarcy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        vector<vector<Point>> contours_poly(contours.size());

        int amount = contours.size();
        cout << "amount of contours" << amount << endl;
        //int size_contour = 0;

        string shapes[] = { "cember","ucgen","kare","dikdortgen","besgen","altigen","yedigen","sekizgen" };

        vector<int> kenar_array;

        string shape_string;
        int area;
        string area_s;
        string kenar;

        RotatedRect text_rect;

        for (int i = 0; i < contours.size(); i++)
        {
            approxPolyDP(Mat(contours[i]), contours_poly[i], 15, true);

            drawContours(c_ip_img, contours_poly, i, Scalar(255, 255, 0), 2, 8);

            int size_contour = contours_poly[i].size();


            if (size_contour > 9) {

                shape_string = shapes[0];
            }

            else if (size_contour == 3) {
                shape_string = shapes[1];
            }
            else if (size_contour == 4) {
                shape_string = shapes[3];
            }
            else if (size_contour == 5) {
                shape_string = shapes[4];
            }
            else if (size_contour == 6) {
                shape_string = shapes[5];
            }
            else if (size_contour == 6) {
                shape_string = shapes[5];
            }
            else if (size_contour == 6) {
                shape_string = shapes[5];
            }
            else if (size_contour == 7) {
                shape_string = shapes[6];
            }
            else if (size_contour == 8) {
                shape_string = shapes[7];
            }

            int j = 0;
            Point2f p_1;
            Point2f p_2;
            int dis;


            while (j < size_contour)
            {
                if (j == size_contour - 1) {

                    p_1 = contours_poly[i][j];
                    p_2 = contours_poly[i][0];

                    dis = norm(Mat(p_1), Mat(p_2));

                    Point2i p_off;

                    kenar_array.push_back(dis);

                    kenar = to_string(dis);
                    p_off = (p_1 + p_2) / 2;

                    putText(c_ip_img, kenar, p_off, 1, 1, Scalar(255, 0, 0));

                }

                else {
                    p_1 = contours_poly[i][j];
                    p_2 = contours_poly[i][j + 1];

                    dis = norm(Mat(p_1), Mat(p_2));

                    Point2i p_off;

                    kenar_array.push_back(dis);

                    p_off = (p_1 + p_2) / 2;

                    kenar = to_string(dis);

                    putText(c_ip_img, kenar, p_off, 1, 1, Scalar(255, 0, 0));

                }

                j = j + 1;
            }

            for (int x = 0; x < size_contour; x++) {

                if (x == size_contour - 1) {
                    /* float dot = ((contours_poly[i][0]).x - (contours_poly[i][x].x))
                         * ((contours_poly[i][x-1]).x - (contours_poly[i][x].x)) +
                         ((contours_poly[i][0]).y - (contours_poly[i][x].y))
                         * ((contours_poly[i][x-1]).y - (contours_poly[i][x].y));*/
                    Point2i dot_1 = (contours_poly[i][0]) - (contours_poly[i][x]);
                    Point2i dot_2 = (contours_poly[i][x - 1]) - (contours_poly[i][x]);
                    float dot = Mat(dot_1).dot(Mat(dot_2));

                    float sonuc = dot / (kenar_array[x - 1] * kenar_array[x]);

                    sonuc = 57.295 * acos(sonuc);

                    string sonuc_ = to_string(sonuc);
                    putText(c_ip_img, sonuc_, contours_poly[i][x], 1, 1, Scalar(255, 0, 0));

                }

                if (x == 0) {
                    /*float dot = ((contours_poly[i][x + 1]).x - (contours_poly[i][x].x))
                        * ((contours_poly[i][size_contour - 1]).x - (contours_poly[i][x].x)) +
                        ((contours_poly[i][x + 1]).y - (contours_poly[i][x].y))
                        * ((contours_poly[i][size_contour - 1]).y - (contours_poly[i][x].y));*/


                    Point2i dot_1 = (contours_poly[i][x + 1]) - (contours_poly[i][x]);
                    Point2i dot_2 = (contours_poly[i][size_contour - 1]) - (contours_poly[i][x]);
                    float dot = Mat(dot_1).dot(Mat(dot_2));

                    float sonuc = dot / (kenar_array[size_contour - 1] * kenar_array[x]);

                    sonuc = 57.295 * acos(sonuc);

                    string sonuc_ = to_string(sonuc);
                    putText(c_ip_img, sonuc_, contours_poly[i][x], 1, 1, Scalar(255, 0, 0));

                }

                if (x != 0 && x != size_contour - 1) {

                    /*float dot = ((contours_poly[i][x + 1]).x - (contours_poly[i][x].x))
                        * ((contours_poly[i][x-1]).x - (contours_poly[i][x].x)) +
                        ((contours_poly[i][x + 1]).y - (contours_poly[i][x].y))
                        * ((contours_poly[i][x - 1]).y - (contours_poly[i][x].y));*/

                    Point2i dot_1 = (contours_poly[i][x + 1]) - (contours_poly[i][x]);
                    Point2i dot_2 = (contours_poly[i][x - 1]) - (contours_poly[i][x]);
                    float dot = Mat(dot_1).dot(Mat(dot_2));

                    float sonuc = dot / (kenar_array[x - 1] * kenar_array[x]);

                    sonuc = 57.295 * acos(sonuc);

                    string sonuc_ = to_string(sonuc);
                    putText(c_ip_img, sonuc_, contours_poly[i][x], 1, 1, Scalar(255, 0, 0));

                }
            }
            text_rect = minAreaRect(contours[i]);
            area = contourArea(contours[i]);
            area_s = to_string(area);

            Point2f p(0, 15);
            putText(c_ip_img, shape_string, text_rect.center, 1, 1, Scalar(255, 0, 0));
            putText(c_ip_img, area_s, text_rect.center + p, 1, 1, Scalar(255, 0, 0));
            kenar_array.clear();

        }

        auto end = steady_clock::now();

        double gecen_zaman = double(duration_cast <milliseconds> (end - start).count());
        cout << "time: " << gecen_zaman << "ms" << endl;

        imshow("ip image w text", c_ip_img);
        waitKey(1);
    }
}


int main()
{
    //photo();
    cam();


    return 0;
}
