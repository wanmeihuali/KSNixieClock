#pragma once

const decltype(LOW) bcd_code[10][4] = {
  {LOW, LOW, LOW, LOW},
  {LOW, LOW, LOW, HIGH},
  {LOW, LOW, HIGH, LOW},
  {LOW, LOW, HIGH, HIGH},
  {LOW, HIGH, LOW, LOW},
  {LOW, HIGH, LOW, HIGH},
  {LOW, HIGH, HIGH, LOW},
  {LOW, HIGH, HIGH, HIGH},
  {HIGH, LOW, LOW, LOW},
  {HIGH, LOW, LOW, HIGH},
};

class NixieTubeDriver
{
public:
	NixieTubeDriver(int pin_A, int pin_B, int pin_C, int pin_D) :
		_pin_A(pin_A), _pin_B(pin_B), _pin_C(pin_C), _pin_D(pin_D) {
		pinMode(_pin_A, OUTPUT);
		pinMode(_pin_B, OUTPUT);
		pinMode(_pin_C, OUTPUT);
		pinMode(_pin_D, OUTPUT);
		_digit = 0;
		_outputDigit(_digit);
	}

	void displayDigit(int digit) {
			_digit = digit;
			_outputDigit(digit);
		
	}
private:
	int _pin_A, _pin_B, _pin_C, _pin_D;
	int _digit;

	void _outputDigit(int digit) {
		digitalWrite(_pin_A, bcd_code[digit][3]);
		digitalWrite(_pin_B, bcd_code[digit][2]);
		digitalWrite(_pin_C, bcd_code[digit][1]);
		digitalWrite(_pin_D, bcd_code[digit][0]);
	}
};
