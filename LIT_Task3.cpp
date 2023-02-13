#include <iostream>
#include <map>
#include <string>

class StringRepresentation
{
private:
	std::string str = "";
	int num = 0;

	std::string getHundreds(int);
	void toString();
	
	std::map<int, std::string> ranks{
		{0, "Ноль"},
		{1, "Один"},
		{2, "Два"},
		{3, "Три"},
		{4, "Четыре"},
		{5, "Пять"},
		{6, "Шесть"},
		{7, "Семь"},
		{8, "Восемь"},
		{9, "Девять"},
		{10, "Десять"},
		{11, "Одиннадцать"},
		{12, "Двенадцать"},
		{13, "Тринадцать"},
		{14, "Четырнадцать"},
		{15, "Пятнадцать"},
		{16, "Шестнадцать"},
		{17, "Семнадцать"},
		{18, "Восемнадцать"},
		{19, "Девятнадцать"},
		{20, "Двадцать"},
		{30, "Тридцать"},
		{40, "Сорок"},
		{50, "Пятьдесят"},
		{60, "Шестьдесят"},
		{70, "Семьдесят"},
		{80, "Восемьдесят"},
		{90, "Девяносто"},
		{100, "Сто"},
		{200, "Двести"},
		{300, "Триста"},
		{400, "Четыреста"},
		{500, "Пятьсот"},
		{600, "Шестьсот"},
		{700, "Семьсот"},
		{800, "Восемьсот"},
		{900, "Девятьсот"},
		{1000, "Тысяч"},
		{1001, "Тысяча"},
		{1002, "Тысячи"},
		{1003, "Тысячи"},
		{1004, "Тысячи"},
		{1000000, "Миллионов"},
		{1000001, "Миллион"},
		{1000002, "Миллиона"},
		{1000003, "Миллиона"},
		{1000004, "Миллиона"}
	};

public:
	StringRepresentation(int t = 0) : num(t) {
		toString();
	}
	void setNumber(int t){
		num = t;
		toString();
	}

	std::string getString() {
		return str;
	}
	int getNumber() {
		return num;
	}
};

std::string StringRepresentation::getHundreds(int t) {
	std::string result = "";
	int hundreds = t / 100 * 100;
	int tens = t % 100 / 10 * 10;
	int units = t % 10;

	if (hundreds > 0) {
		result += ranks[hundreds];
		if (tens > 0 || units > 0) {
			result += " ";
		}
	}
	if (tens == 10) {
		if (units == 0) {
			result += ranks[tens];
		}
		else if (units > 0) {
			result += ranks[tens + units];
		}
	}
	else if (tens >= 20) {
		result += ranks[tens];
		if (units > 0) {
			result += " " + ranks[units];
		}
	}
	else {
		result += ranks[units];
	}
	return result;
};

void StringRepresentation::toString() {
	str = "";
	int n = 1, tmp = num;

	if (num == 0) {
		str = ranks[num];
	}
	else {
		while (tmp > 0) {
			int part = tmp % 1000;

			if (part > 0) {
				std::string t_str = getHundreds(part);
				int unit = part % 10;

				if (n == 1000) {
					if (unit == 1) {
						t_str.replace(t_str.end() - 2, t_str.end(), "на");
					}
					else if (unit == 2) {
						t_str.replace(t_str.end() - 1, t_str.end(), "е");
					}
				}

				if (n > 1) {
					if (unit >= 0 && unit <= 4) {
						t_str += " " + ranks[n + unit];
					}
					else {
						t_str += " " + ranks[n];
					}
				}

				if (t_str != "") {
					str = t_str + " " + str;
				}
			}

			n *= 1000;
			tmp /= 1000;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int number = 0;
	StringRepresentation sr;

	while (number >= 0) {
		std::cout << "Input: ";
		std::cin >> number;
		sr.setNumber(number);
		std::cout << "Output: " << sr.getString() << std::endl;
	}
	
	return 0;
}
