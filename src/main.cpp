/**
 * @file main.cpp
 * @author pdave1 (pdave1@umd.edu)
 * @brief The program takes input in form of total input parts to be placed into , input specific small/medium/large/extralarge boxes of user defined size.The box filling starts from biggest and either it fills completely or doesnt fill. Final reult is the number of boxes filled and remaining pieces. 
 * @version 0.1
 * @date 2021-09-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include<string>
/**
 * @brief Box struct contains variables to store number of boxes of different dimemsions
 * 
 */
struct boxes{
    unsigned int small;
    unsigned int medium;
    unsigned int large;
    unsigned int extraLarge;
};

/**
 * @brief maxPartPerBox struct contains variables to store maximum number of parts boxes of diferent could fit.
 * 
 */
struct maxPartsPerBox{
    unsigned int maxSmall;
    unsigned int maxMedium;
    unsigned int maxLarge;
    unsigned int maxExtraLarge;
};

/**
 * @brief final struct contains final number of boxes that contain parts.
 * 
 */
struct final{
	unsigned int finalSmall;
    unsigned int finalMedium;
    unsigned int finalLarge;
    unsigned int finalExtraLarge;
	unsigned int remainder;
};

/**
 * @brief Get the total parts object
 * 
 * @return unsigned int 
 */
//Declaration of functions.

unsigned int get_total_parts();//he number of parts your robot will need to place.
void get_total_boxes(boxes& boxes); //Total s/m/l/xl parts.
void get_part_per_box(maxPartsPerBox& max); //max parts pers box.
void fill_up_boxes(const boxes& ,const maxPartsPerBox& , final&, const int totalParts);//returns number of boxes filled & remaining pieces.



/**
 * @brief Prompts user to enter only positive integers.
 * 
 * @param str 
 * @return int 
 */

int returnInteger(std::string str){
	int boxes{};
	while(true){
		int y = 0;	
    	for(int x = 0 ; x < str.length();x++){
        	if(!std::isdigit(str[x])){
				y = 1;
            	break;
        	}
    	}
    	if(y == 1){
        	std::cout << "Enter a positive number: " << std::endl;
        	std::cin >> str;
    	}
    	if (y == 0){
        	break;
    	} 
	}
	boxes = std::stoi(str);
	return boxes;

}

/**
 * @brief Get the total parts object
 * 
 * @return unsigned int 
 */

unsigned int get_total_parts(){
	int boxes{};
	std::cout << "How many parts in total?: " << std::endl;
	 
	std::string str{};
	std::cin >> str;
	
	
	return returnInteger(str);
	
}



/**
 * @brief Get the total boxes object
 * 
 * @param boxes 
 */

void get_total_boxes(boxes& boxes){
	std::cout << "How many boxes for S/M/L/XL? " << std::endl;
	std::string strSmall{};
	std::string strMedium{};
	std::string strLarge{};
	std::string strExtraLarge{};
	std::cin >> strSmall >>strMedium >> strLarge >>  strExtraLarge ;
	boxes.small = returnInteger(strSmall);
	boxes.medium = returnInteger(strMedium);
	boxes.large = returnInteger(strLarge);
	boxes.extraLarge = returnInteger(strExtraLarge);
} 


/**
 * @brief Get the part per box object
 * 
 * @param max 
 */

void get_part_per_box(maxPartsPerBox& max){
	std::cout << "How many parts per box for S/M/L/XL?: " << std::endl;
	std::string maxSmall{};
	std::string maxMedium{};
	std::string maxLarge{};
	std::string maxExtraLarge{};
	std::cin >> maxSmall >>maxMedium >> maxLarge >>  maxExtraLarge ;
	max.maxSmall = returnInteger(maxSmall);
	max.maxMedium = returnInteger(maxMedium);
	max.maxLarge = returnInteger(maxLarge);
	max.maxExtraLarge = returnInteger(maxExtraLarge);

	
		if(max.maxSmall > max.maxMedium || max.maxMedium > max.maxLarge || max.maxLarge > max.maxExtraLarge){
			std::cout << "Enter a positive number: " << std::endl;
			std::cin >> maxSmall >>maxMedium >> maxLarge >>  maxExtraLarge ;
			max.maxSmall = returnInteger(maxSmall);
			max.maxMedium = returnInteger(maxMedium);
			max.maxLarge = returnInteger(maxLarge);
			max.maxExtraLarge = returnInteger(maxExtraLarge);
		}
		
			
}


/**
 * @brief get final value of filled boxes and remaining parts.
 * 
 * @param box 
 * @param max 
 * @param totalParts 
 */

void fill_up_boxes(const boxes& box,const maxPartsPerBox& max, final& final,int totalParts){
	unsigned int filledSmall{0};
	unsigned int filledMedium{0};
	unsigned int filledLarge{0};
	unsigned int filledExtraLarge{0};
	int remaining = totalParts;

	int small = box.small;
	int medium = box.medium;  
	int large = box.large; 
	int extraLarge = box.extraLarge;

	int maxExtraLarge = max.maxExtraLarge; 
	int maxLarge = max.maxLarge;
	int maxMedium = max.maxMedium;
	int maxSmall = max.maxSmall;


	std::cout << "Boxes that can be built with " << totalParts <<  " pegs: " << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	while(remaining >= maxExtraLarge && extraLarge != 0){
		extraLarge = extraLarge -1;
		remaining = remaining - max.maxExtraLarge;
		filledExtraLarge = filledExtraLarge + 1;
	}
	std::cout <<  "XL box ("  << box.extraLarge << " x " << max.maxExtraLarge << " max): " << filledExtraLarge  <<  " remaining parts: " << remaining << std::endl;

	while(remaining >= maxLarge && large != 0){
		large = large - 1;
		remaining = remaining - max.maxLarge;
		filledLarge = filledLarge + 1;
	}
	std::cout <<  "L box ("  << box.large << " x " << max.maxLarge << " max): " << filledLarge  <<  " remaining parts: " << remaining << std::endl;


	while(remaining >= maxMedium && medium != 0){
		medium = medium - 1;
		remaining = remaining - max.maxMedium;
		filledMedium = filledMedium + 1;
	}	
	std::cout <<  "M box ("  << box.medium << " x " << max.maxMedium << " max): " << filledMedium  <<  " remaining parts: " << remaining << std::endl;

	while(remaining >= maxSmall && small != 0){
		small = small - 1;
		remaining = remaining - max.maxSmall;
		filledSmall = filledSmall + 1;
	}
	
	std::cout <<  "S box ("  << box.small << " x " << max.maxSmall << " max): " << filledSmall  <<  " remaining parts: " << remaining << std::endl;
	std::cout << "parts not in the box: " << remaining << std::endl;
}

int main()
{
	int totalParts = get_total_parts();
	boxes box;
	get_total_boxes(box);
	maxPartsPerBox maxBoxes;
	get_part_per_box(maxBoxes);
	final final;
	fill_up_boxes(box ,maxBoxes, final,totalParts);
	
}