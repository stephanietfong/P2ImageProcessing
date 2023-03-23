// COP3503C Project 2: Image Processing
// Stephanie Fong, created 3/15/23

#include <iostream>
#include <fstream>
#include <filesystem>
#include "Image.h"
using namespace std;

bool FileExists(const string& filename);
Image Readfile(const string& filename);
void Writefile(const string& filename, Image& image);
Image Add(Image& file1, Image& file2);
Image Multiply(Image& file1, Image& file2);
Image Subtract(Image& topImage, Image& bottomImage);
Image Screen(Image& topImage, Image& bottomImage);
Image Overlay(Image& topImage, Image& bottomImage);
void Op1_Multiply(const string& file_1, const string& file_2, const string& output_file);
void Op2_Subtract(const string& topImage, const string& bottomImage, const string& output_file);
void Op3_MultiplyScreen(const string& file_1, const string& file_2, const string& screenfile, const string& output_file);
void Op4_MultiplySubtract(const string& file_1, const string& file_2, const string& bottomfile, const string& output_file);
void Op5_Overlay(const string& topImage, const string& bottomImage, const string& output_file);
void Op6_AddBlue(const string& image, int value, const string& output_file);
void Op6_AddGreen(const string& image, int value, const string& output_file);
void Op6_AddRed(const string& image, int value, const string& output_file);
void Op7_ScaleBlue(const string& image, int value, const string& output_file);
void Op7_ScaleGreen(const string& image, int value, const string& output_file);
void Op7_ScaleRed(const string& image, int value, const string& output_file);
void Op8_OnlyBlue(const string& image, const string& output_file);
void Op8_OnlyGreen(const string& image, const string& output_file);
void Op8_OnlyRed(const string& image, const string& output_file);
void Op9_Combine(const string& red_image, const string& green_image, const string& blue_image, const string& output_file);
void Op10_Flip(const string& image, const string& output_file);

int main(int argc, char* argv[]) {
	if ((argc < 2) || (argv[1] == "--help")) {
		cout << "Project 2: Image Processing, Spring 2023" << endl;
		cout << endl;
		cout << "Usage:" << endl;
		cout << "	./project2.out [output] [firstImage] [method] [...]" << endl;
	}
	else {
		string output_arg = static_cast<string>(argv[1]);
		if (output_arg.find(".tga") != std::string::npos) {
			cout << "Argument 1: " << argv[1] << endl;
			string tracking_image_arg = static_cast<string>(argv[2]);
			cout << "Argument 2: " << tracking_image_arg << endl;
			if (tracking_image_arg.find("tga") != std::string::npos) {
				if (FileExists("input/" + tracking_image_arg)) {
					cout << "File loaded" << endl;
					// task 1: multiply layer1.tga and pattern1.tga
					Op1_Multiply("input/layer1.tga", "input/pattern1.tga", "output/part1.tga");

					// task 2: subtract layer2.tga from car.tga
					Op2_Subtract("input/car.tga", "input/layer2.tga", "output/part2.tga");

					// task 3: multiply layer1.tga and pattern2.tga and screen with text.tga
					Op3_MultiplyScreen("input/layer1.tga", "input/pattern2.tga", "input/text.tga", "output/part3.tga");

					// task 4: subtract pattern2.tga from product of layer2.tga and circles.tga
					Op4_MultiplySubtract("input/layer2.tga", "input/circles.tga", "input/pattern2.tga", "output/part4.tga");

					// task 5: overlay layer1.tga and pattern1.tga
					Op5_Overlay("input/layer1.tga", "input/pattern1.tga", "output/part5.tga");

					// task 6: add 200 to green of car.tga
					Op6_AddGreen("input/car.tga", 200, "output/part6.tga");

					// task 7: scale red by 4 and blue by 0 of car.tga
					Op7_ScaleRed("input/car.tga", 4, "output/part7.tga");
					Op7_ScaleBlue("output/part7.tga", 0, "output/part7.tga");

					// task 8: split car.tga into 3 files, one for each channel
					Op8_OnlyBlue("input/car.tga", "output/part8_b.tga");
					Op8_OnlyGreen("input/car.tga", "output/part8_g.tga");
					Op8_OnlyRed("input/car.tga", "output/part8_r.tga");

					// task 9: combine layer_red.tga, layer_green.tga, and layer_blue.tga into one file
					Op9_Combine("input/layer_red.tga", "input/layer_green.tga", "input/layer_blue.tga", "output/part9.tga");

					// task 10: rotate text2.tga 180 degrees
					Op10_Flip("input/text2.tga", "output/part10.tga");
				}
				else {
					cout << "File does not exist." << endl;
				}
			}
			else {
				cout << "Invalid file name." << endl;
			}
		}
		else {
			cout << "Invalid file name." << endl;
		}
	}

	//// task 1: multiply layer1.tga and pattern1.tga
	//Op1_Multiply("C:/Users/steph/VS Projects/project2/project2/input/layer1.tga", "C:/Users/steph/VS Projects/project2/project2/input/pattern1.tga", "output / part1.tga");

	//// task 2: subtract layer2.tga from car.tga
	//Op2_Subtract("input\\car.tga", "input\\layer2.tga", "output\\part2.tga");

	//// task 3: multiply layer1.tga and pattern2.tga and screen with text.tga
	//Op3_MultiplyScreen("input/layer1.tga", "input/pattern2.tga", "input/text.tga", "output/part3.tga");

	//// task 4: subtract pattern2.tga from product of layer2.tga and circles.tga
	//Op4_MultiplySubtract("input/layer2.tga", "input/circles.tga", "input/pattern2.tga", "output/part4.tga");

	//// task 5: overlay layer1.tga and pattern1.tga
	//Op5_Overlay("input/layer1.tga", "input/pattern1.tga", "output/part5.tga");

	//// task 6: add 200 to green of car.tga
	//Op6_AddGreen("input/car.tga", 200, "output/part6.tga");

	//// task 7: scale red by 4 and blue by 0 of car.tga
	//Op7_ScaleRed("input/car.tga", 4, "output/part7.tga");
	//Op7_ScaleBlue("output/part7.tga", 0, "output/part7.tga");

	//// task 8: split car.tga into 3 files, one for each channel
	//Op8_OnlyBlue("input/car.tga", "output/part8_b.tga");
	//Op8_OnlyGreen("input/car.tga", "output/part8_g.tga");
	//Op8_OnlyRed("input/car.tga", "output/part8_r.tga");

	//// task 9: combine layer_red.tga, layer_green.tga, and layer_blue.tga into one file
	//Op9_Combine("input/layer_red.tga", "input/layer_green.tga", "input/layer_blue.tga", "output/part9.tga");

	//// task 10: rotate text2.tga 180 degrees
	//Op10_Flip("input/text2.tga", "output/part10.tga");

	return 0;
}

bool FileExists(const string& filename) {
	fstream file(filename, ios_base::in | ios_base::binary);
	return file.is_open();
}

Image Readfile(const string& filename) {
	fstream file(filename, ios_base::in | ios_base::binary);
	if (file.is_open()) {
		cout << "file opened" << endl;
		Image image;
		char idLength;
		file.read(&idLength, 1);
		image.idLength = idLength;

		char colorMap;
		file.read(&colorMap, 1);
		image.colorMapType = colorMap;

		char dataType;
		file.read(&dataType, 1);
		image.dataTypeCode = dataType;

		short colorMapOrigin;
		file.read((char*)&colorMapOrigin, 2);
		image.colorMapOrigin = colorMapOrigin;

		short colorMapLength;
		file.read((char*)&colorMapLength, 2);
		image.colorMapLength = colorMapLength;

		char colorMapDepth;
		file.read(&colorMapDepth, 1);
		image.colorMapDepth = colorMapDepth;

		short x;
		file.read((char*)&x, 2);
		image.xOrigin = x;

		short y;
		file.read((char*)&y, 2);
		image.yOrigin = y;

		short width;
		file.read((char*)&width, 2);
		image.width = width;

		short height;
		file.read((char*)&height, 2);
		image.height = height;

		char bitsPerPixel;
		file.read(&bitsPerPixel, 1);
		image.bitsPerPixel = bitsPerPixel;

		char imageDes;
		file.read(&imageDes, 1);
		image.imageDescriptor = imageDes;

		for (unsigned int i = 0; i < (width * height); i++) {
			unsigned char blue;
			file.read((char*)&blue, 1);
			image.imageData.push_back(blue);

			unsigned char green;
			file.read((char*)&green, 1);
			image.imageData.push_back(green);

			unsigned char red;
			file.read((char*)&red, 1);
			image.imageData.push_back(red);
		}
		return image;
	}
	else {
		cout << "file not opened" << endl;
		Image image;
		return image;
	}
}

void Writefile(const string& filename, Image& image) {
	fstream newimage(filename, ios_base::out | ios_base::binary);
	newimage.write(&image.idLength, 1);
	newimage.write(&image.colorMapType, 1);
	newimage.write(&image.dataTypeCode, 1);
	newimage.write((char*)&image.colorMapOrigin, 2);
	newimage.write((char*)&image.colorMapLength, 2);
	newimage.write(&image.colorMapDepth, 1);
	newimage.write((char*)&image.xOrigin, 2);
	newimage.write((char*)&image.yOrigin, 2);
	newimage.write((char*)&image.width, 2);
	newimage.write((char*)&image.height, 2);
	newimage.write(&image.bitsPerPixel, 1);
	newimage.write(&image.imageDescriptor, 1);
	for (unsigned int i = 0; i < image.imageData.size(); i++) {
		newimage.write((char*)&image.imageData.at(i), 1);
	}
}

Image Add(Image& file1, Image& file2) {
	Image newimage = file1;
	for (unsigned int i = 0; i < newimage.imageData.at(i); i++) {
		int temp = newimage.imageData.at(i) + file2.imageData.at(i);
		if (temp > 255) {
			temp = 255;
		}
		newimage.imageData.at(i) = temp;
	}
	return newimage;
}

Image Multiply(Image& file1, Image& file2) {
	Image newimage = file1;
	for (unsigned int i = 0; i < newimage.imageData.size(); i++) {
		float norm1 = float(newimage.imageData.at(i)) / 255;
		float norm2 = float(file2.imageData.at(i)) / 255;
		float temp = (norm1 * norm2 * 255) + 0.5f;
		newimage.imageData.at(i) = int(temp);
	}
	return newimage;
}

Image Subtract(Image& topImage, Image& bottomImage) {
	Image newimage = topImage;
	for (unsigned int i = 0; i < newimage.imageData.size(); i++) {
		int temp = newimage.imageData.at(i) - bottomImage.imageData.at(i);
		if (temp < 0) {
			temp = 0;
		}
		newimage.imageData.at(i) = temp;
	}
	return newimage;
}

Image Screen(Image& topImage, Image& bottomImage) {
	Image newimage = topImage;
	for (unsigned int i = 0; i < newimage.imageData.size(); i++) {
		float norm_top = float(newimage.imageData.at(i)) / 255;
		float norm_bottom = float(bottomImage.imageData.at(i)) / 255;
		float temp = (1 - ((1 - norm_top) * (1 - norm_bottom))) * 255 + 0.5f;
		newimage.imageData.at(i) = int(temp);
	}
	return newimage;
}

Image Overlay(Image& topImage, Image& bottomImage) {
	Image newimage = topImage;
	for (unsigned int i = 0; i < newimage.imageData.size(); i++) {
		float norm_top = float(newimage.imageData.at(i)) / 255;
		float norm_bottom = float(bottomImage.imageData.at(i)) / 255;
		if (norm_bottom > 0.5) {
			float temp = (1 - (2 * (1 - norm_top) * (1 - norm_bottom))) * 255 + 0.5f;
			newimage.imageData.at(i) = int(temp);
		}
		else {
			float temp = (2 * norm_top * norm_bottom) * 255 + 0.5f;
			newimage.imageData.at(i) = int(temp);
		}
	}
	return newimage;
}

void Op1_Multiply(const string& file_1, const string& file_2, const string& output_file) {
	Image file1 = Readfile(file_1);
	Image file2 = Readfile(file_2);
	Image result = Multiply(file1, file2);
	Writefile(output_file, result);
}

void Op2_Subtract(const string& topImage, const string& bottomImage, const string& output_file) {
	Image top = Readfile(topImage);
	Image bottom = Readfile(bottomImage);
	Image result = Subtract(top, bottom);
	Writefile(output_file, result);
}

void Op3_MultiplyScreen(const string& file_1, const string& file_2, const string& screenfile, const string& output_file) {
	Image file1 = Readfile(file_1);
	Image file2 = Readfile(file_2);
	Image screen = Readfile(screenfile);
	Image product = Multiply(file1, file2);
	Image result = Screen(product, screen);
	Writefile(output_file, result);
}

void Op4_MultiplySubtract(const string& file_1, const string& file_2, const string& bottomfile, const string& output_file) {
	Image file1 = Readfile(file_1);
	Image file2 = Readfile(file_2);
	Image bottom = Readfile(bottomfile);
	Image product = Multiply(file1, file2);
	Image result = Subtract(product, bottom);
	Writefile(output_file, result);
}

void Op5_Overlay(const string& topImage, const string& bottomImage, const string& output_file) {
	Image top = Readfile(topImage);
	Image bottom = Readfile(bottomImage);
	Image result = Overlay(top, bottom);
	Writefile(output_file, result);
}

void Op6_AddBlue(const string& image, int value, const string& output_file) {
	Image newimage = Readfile(image);
	for (unsigned int i = 0; i < newimage.imageData.size(); i += 3) {
		int temp = int(newimage.imageData.at(i)) + value;
		if (temp > 255) {
			temp = 255;
		}
		newimage.imageData.at(i) = temp;
	}
	Writefile(output_file, newimage);
}

void Op6_AddGreen(const string& image, int value, const string& output_file) {
	Image newimage = Readfile(image);
	for (unsigned int i = 1; i < newimage.imageData.size(); i += 3) {
		int temp = int(newimage.imageData.at(i)) + value;
		if (temp > 255) {
			temp = 255;
		}
		newimage.imageData.at(i) = temp;
	}
	Writefile(output_file, newimage);
}

void Op6_AddRed(const string& image, int value, const string& output_file) {
	Image newimage = Readfile(image);
	for (unsigned int i = 2; i < newimage.imageData.size(); i += 3) {
		int temp = int(newimage.imageData.at(i)) + value;
		if (temp > 255) {
			temp = 255;
		}
		newimage.imageData.at(i) = temp;
	}
	Writefile(output_file, newimage);
}

void Op7_ScaleBlue(const string& image, int value, const string& output_file) {
	Image newimage = Readfile(image);
	for (unsigned int i = 0; i < newimage.imageData.size(); i += 3) {
		int temp = newimage.imageData.at(i) * value;
		if (temp > 255) {
			temp = 255;
		}
		newimage.imageData.at(i) = temp;
	}
	Writefile(output_file, newimage);
}

void Op7_ScaleGreen(const string& image, int value, const string& output_file) {
	Image newimage = Readfile(image);
	for (unsigned int i = 1; i < newimage.imageData.size(); i += 3) {
		int temp = newimage.imageData.at(i) * value;
		if (temp > 255) {
			temp = 255;
		}
		newimage.imageData.at(i) = temp;
	}
	Writefile(output_file, newimage);
}

void Op7_ScaleRed(const string& image, int value, const string& output_file) {
	Image newimage = Readfile(image);
	for (unsigned int i = 2; i < newimage.imageData.size(); i += 3) {
		int temp = newimage.imageData.at(i) * value;
		if (temp > 255) {
			temp = 255;
		}
		newimage.imageData.at(i) = temp;
	}
	Writefile(output_file, newimage);

}

void Op8_OnlyBlue(const string& image, const string& output_file) {
	Image originalimage = Readfile(image);
	Image newimage = Readfile(image);
	int bluepixelnum = 0;
	for (unsigned int i = 1; i < newimage.imageData.size(); i += 3) {
		newimage.imageData.at(i) = originalimage.imageData.at(bluepixelnum);
		newimage.imageData.at(i + 1) = originalimage.imageData.at(bluepixelnum);
		bluepixelnum += 3;
	}
	Writefile(output_file, newimage);
}

void Op8_OnlyGreen(const string& image, const string& output_file) {
	Image originalimage = Readfile(image);
	Image newimage = Readfile(image);
	int greenpixelnum = 1;
	for (unsigned int i = 0; i < newimage.imageData.size(); i += 3) {
		newimage.imageData.at(i) = originalimage.imageData.at(greenpixelnum);
		newimage.imageData.at(i + 2) = originalimage.imageData.at(greenpixelnum);
		greenpixelnum += 3;
	}
	Writefile(output_file, newimage);
}

void Op8_OnlyRed(const string& image, const string& output_file) {
	Image originalimage = Readfile(image);
	Image newimage = Readfile(image);
	int redpixelnum = 2;
	for (unsigned int i = 0; i < newimage.imageData.size(); i += 3) {
		newimage.imageData.at(i) = originalimage.imageData.at(redpixelnum);
		newimage.imageData.at(i + 1) = originalimage.imageData.at(redpixelnum);
		redpixelnum += 3;
	}
	Writefile(output_file, newimage);
}

void Op9_Combine(const string& red_image, const string& green_image, const string& blue_image, const string& output_file) {
	Image newimage = Readfile(red_image);
	Image greenimage = Readfile(green_image);
	Image blueimage = Readfile(blue_image);
	for (unsigned int i = 0; i < newimage.imageData.size(); i += 3) {
		newimage.imageData.at(i) = blueimage.imageData.at(i);
	}
	for (unsigned int i = 1; i < newimage.imageData.size(); i += 3) {
		newimage.imageData.at(i) = greenimage.imageData.at(i);
	}
	Writefile(output_file, newimage);
}

void Op10_Flip(const string& image, const string& output_file) {
	Image originalimage = Readfile(image);
	Image newimage = Readfile(image);
	int pixelnum = originalimage.imageData.size() - 3;
	for (unsigned int i = 0; i < newimage.imageData.size(); i += 3) {
		newimage.imageData.at(i) = originalimage.imageData.at(pixelnum);
		newimage.imageData.at(i + 1) = originalimage.imageData.at(pixelnum + 1);
		newimage.imageData.at(i + 2) = originalimage.imageData.at(pixelnum + 2);
		pixelnum -= 3;
	}
	Writefile(output_file, newimage);
}