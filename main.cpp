#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <stdio.h>


class Cryption{
	public:
	std::string toEncrypt;
	std::string encrypted;
	std::string decrypted;
	char key;
	
	void setString(void);
	void setKey(void);
	void Encrypt(void);
	void Decrypt(void);
	void printEncrypted(void);
	void printDecrypted(void);
	void printToEncrypt(void);
	void printKey(void);
};

void Cryption::setString(void){
	std::cout << "Give a new string that you want to encrypt" << std::endl;
	std::cin >> toEncrypt;
}

void Cryption::printEncrypted(void){
	std::cout << "Encrypted value = " << encrypted << std::endl;
}

void Cryption::printDecrypted(void){
	std::cout << "Decrypted value = " << decrypted << std::endl;
}

void Cryption::printToEncrypt(void){
	std::cout << "Value you want to encrypt = " << toEncrypt << std::endl;
}

void Cryption::setKey(void){
	std::cout << "Give a new key that you want to use to encrypt your string." << std::endl;
	std::cin >> key;
}

void Cryption::printKey(void){
	std::cout << "Value of your encrypt/decrypt key = " << key << std::endl;
}

void Cryption::Encrypt(void){
	for(int temp=0; temp < toEncrypt.size(); temp++){
		encrypted += toEncrypt[temp] ^ (int(key) + temp) % 255;
	}
}

void Cryption::Decrypt(void){
	for(int temp=0; temp < toEncrypt.size(); temp++){
		decrypted += encrypted[temp] ^ (int(key) + temp) % 255;
	}
}

//SDL Properties
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char* args[]){
	//SDL Execution
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Renderer* renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "SDL could not initialize! SDL_Error = " << SDL_GetError() << std::endl;
	}else{
		window = SDL_CreateWindow("Simple Encrypt/Decrypt Program", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == NULL){
			std::cout << "Window could not be created! SDL_Error = " << SDL_GetError() << std::endl;
			SDL_Quit();
			return 1;
		}else{
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);
			SDL_Delay(2000);
		}
	}

	/*
	Cryption c;
	c.setString();
	c.setKey();
	c.printToEncrypt();
	c.printKey();
	std::cout << "Values before encryption." << std::endl;
	c.printEncrypted();
	c.printDecrypted();
	c.Encrypt();
	std::cout << "Values after encryption but before decryption." << std::endl;
	c.printEncrypted();
	c.printDecrypted();
	c.Decrypt();
	std::cout << "Values after encryption and decryption." << std::endl;
	c.printEncrypted();
	c.printDecrypted();
	*/
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

