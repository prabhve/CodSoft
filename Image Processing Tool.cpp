#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("input.jpg");
    
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    imshow("Original Image", image);
    
    cout << "Choose an operation:" << endl;
    cout << "1. Resize" << endl;
    cout << "2. Crop" << endl;
    cout << "3. Apply Filter" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            int newWidth, newHeight;
            cout << "Enter new width: ";
            cin >> newWidth;
            cout << "Enter new height: ";
            cin >> newHeight;

            resize(image, image, Size(newWidth, newHeight));
            break;
        case 2:
            int x, y, width, height;
            cout << "Enter x-coordinate of top-left corner: ";
            cin >> x;
            cout << "Enter y-coordinate of top-left corner: ";
            cin >> y;
            cout << "Enter width: ";
            cin >> width;
            cout << "Enter height: ";
            cin >> height;

            Rect roi(x, y, width, height);
            image = image(roi);
            break;
        case 3:
            int filterType;
            cout << "Choose filter type:" << endl;
            cout << "1. Gaussian Blur" << endl;
            cout << "2. Median Blur" << endl;
            cout << "3. Bilateral Filter" << endl;
            cin >> filterType;

            switch (filterType) {
                case 1:
                    GaussianBlur(image, image, Size(5, 5), 0);
                    break;
                case 2:
                    medianBlur(image, image, 5);
                    break;
                case 3:
                    bilateralFilter(image, image, 9, 75, 75);
                    break;
                default:
                    cout << "Invalid filter type" << endl;
                    break;
            }
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    imshow("Processed Image", image);
    waitKey(0);

    return 0;
}

