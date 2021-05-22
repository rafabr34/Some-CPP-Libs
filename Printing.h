#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <memory.h>
#include <wincon.h>


using std::string;
class Printing
{
public:
	static void Warn(string String);
	static void LowLevelWarn(string String);
	static void Error(string String);
	static void LowLevelError(string String);
	static void Info(string String);
	static string Prompt(string String);
	static void Clear();
	static void ConColor(int Color);
	class Colors;
	class IntColors;
private:
	static void CColor(int Color);
};



class Printing::Colors {
public:
		const char * Reset = "\033[0m";
		const char * Black = "\033[30m";
		const char * Red = "\033[31m";
		const char * Green = "\033[32m";
		const char * Yellow = "\033[33m";
		const char * Blue = "\033[34m";
		const char * Purple = "\033[35m";
		const char * Cyan = "\033[36m";
		const char * White = "\033[37m";
		const char * BoldBlack = "\033[1m\033[30m";
		const char * BoldRed = "\033[1m\033[31m";
		const char * BoldGreen = "\033[1m\033[32m";
		const char * BoldYellow = "\033[1m\033[33m";
		const char * BoldBlue = "\033[1m\033[34m";
		const char * BoldPurple = "\033[1m\033[35m";
		const char * BoldCyan = "\033[1m\033[36m";
		const char * BoldWhite = "\033[1m\033[37m";
};
class Printing::IntColors {
public:	
		int Black = 0;
		int Blue = 1;
		int Green = 2;
		int Cyan = 3;
		int Red = 4;
		int Purple = 5;
		int Yellow = 6;
		int White = 7;
		int BoldBlack = 8;
		int BoldBlue = 9;
		int BoldGreen = 10;
		int BoldCyan = 11;
		int BoldRed = 12;
		int BoldPurple = 13;
		int BoldYellow = 14;
		int BoldWhite = 15;

};

void Printing::CColor(int Color) {
	HANDLE ConHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(ConHandle, (WORD)Color);
}

void Printing::LowLevelWarn(string String) {
	std::cout << "[";
	CColor(14);
	std::cout << "LOW_LEVEL_WARNING";
	CColor(7);
	std::cout << "]" << " " + String + "\n";
}

void Printing::Warn(string String) {
	std::cout << "[";
	CColor(6);
	std::cout << "WARNING";
	CColor(7);
	std::cout << "]" << " " + String + "\n";
}

void Printing::Error(string String) {
	std::cout << "[";
	CColor(4);
	std::cout << "ERROR";
	CColor(7);
	std::cout << "]" << " " + String + "\n";
}

void Printing::LowLevelError(string String) {
	std::cout << "[";
	CColor(12);
	std::cout << "LOW_LEVEL_ERROR";
	CColor(7);
	std::cout << "]" << " " + String + "\n";
}

void Printing::Info(string String) {
	std::cout << "[";
	CColor(11);
	std::cout << "INFO";
	CColor(7);
	std::cout << "]" << " " + String + "\n";
}

string Printing::Prompt(string String) {
	std::cout << "[";
	CColor(3);
	std::cout << "PROMPT";
	CColor(7);
	std::cout << "]" << " " + String + "\n";
	string StringPointer;
	std::cin >> StringPointer;
	return StringPointer;
}

void Printing::ConColor(int Color) {
	CColor(Color);
}
void Printing::Clear() {
	system("cls");
}