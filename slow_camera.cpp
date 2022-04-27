/*
This is the slow implementation of OpenCv on C++

author: nyzex (Qos)
*/


#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>


class AccessCam{

    cv::VideoCapture fr(int);
    cv::Mat image,dst;

    public:
        AccessCam(){
        
            cv::namedWindow("Frames");
        
        }   

    public:
        void display(){
            
            cv::VideoCapture fr(0);
            
            if(!fr.isOpened()){
                std::cout<<"Stream not available";
            }
            while(true){
               
                fr >> image;
                cv::resize(image, dst, cv::Size(1024, 768), 0, 0, cv::INTER_CUBIC); 
                cv::imshow("Stream", dst);
                

                if(cv::waitKey(1) == 27){

                    break;
                }
                        
            }
        }
};


int main(){

    AccessCam x; 
    x.display();

    return 0;
}