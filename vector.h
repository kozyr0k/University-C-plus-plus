#pragma once
#include <iostream>
//#define DEBUG

template <typename T>
class vector
{
public:
	vector()
	{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
		cout << "Викликався конструктор без параметрів класу vector - " << this << endl << endl;
#endif 
		_vector = NULL;
		_vectorSize = 0;
	}
	vector(int vectorSize) //конструктор з параметрами
	{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
		cout << "Викликався конструктор з параметрами класу vector - " << this << endl << endl;
#endif 
		_vectorSize = vectorSize;
		if (!(_vector = (T*) new T[_vectorSize]))
		{
			std::cout << "Не вдалося виділити пам'ять під вектор!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _vectorSize; i++)
		{
			_vector[i] = 0;
		}
	}
	vector(const vector& other) //конструктор копіювання
	{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
		cout << "Викликався конструктор копіювання класу vector - " << this << endl << endl;
#endif 
		_vectorSize = other._vectorSize;
		if (!(_vector = (T*) new T[_vectorSize]))
		{
			std::cout << "Не вдалося виділити пам'ять під вектор!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _vectorSize; i++)
		{
			_vector[i] = other._vector[i];
		}
	}
	~vector() //деструктор
	{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
		cout << "Викликався деструктор класу vector - " << this << endl << endl;
#endif 
		delete[] _vector;
	}
	vector operator=(const vector& other)
	{
		if (this == &other)
		{
#ifdef DEBUG
			cout << "Викликане самоприсвоювання!" << endl;
#endif
			return *this;
		}
		if (_vectorSize > 0)
		{
			delete[] _vector;
		}

		_vectorSize = other._vectorSize;
		if (!(_vector = (T*) new T[_vectorSize]))
		{
			std::cout << "Не вдалося виділити пам'ять під вектор!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _vectorSize; i++)
		{
			_vector[i] = other._vector[i];
		}
		return *this;
	}
	vector operator=(int vectorSize)
	{
		if (vectorSize != _vectorSize)
		{
			delete[] _vector;
			if (!(_vector = (T*) new T[_vectorSize]))
			{
				std::cout << "Не вдалося виділити пам'ять під вектор!" << std::endl;
				exit(0);
			}
		}
		_vectorSize = vectorSize;
		for (int i = 0; i < vectorSize; i++)
		{
			_vector[i] = 0;
		}
		return *this;
	}
	vector operator=(std::array<T, 2> sizeAndNumber)
	{
		if (_vectorSize!=sizeAndNumber[0])
		{
			delete[] _vector;

			_vectorSize = sizeAndNumber[0];
			if (!(_vector = (T*) new T[_vectorSize]))
			{
				std::cout << "Не вдалося виділити пам'ять під вектор!" << std::endl;
				exit(0);
			}
		}
		for (int i = 0; i < _vectorSize; i++)
		{
			_vector[i] = sizeAndNumber[1];
		}
		return *this;
	}
	vector operator+(const vector& other)
	{
		if (_vectorSize != other._vectorSize)
		{
			std::cout << "Неможливо додати задані вектори!" << std::endl;
			return *this;
		}
		for (int i = 0; i < _vectorSize; i++)
		{
			_vector[i] += other._vector[i];
		}
		return *this;
	}
	vector operator-(const vector& other)
	{
		if (_vectorSize != other._vectorSize)
		{
			std::cout << "Неможливо відняти задані вектори!" << std::endl;
			return *this;
		}
		for (int i = 0; i < _vectorSize; i++)
		{
			_vector[i] -= other._vector[i];
		}
		return *this;
	}
	vector operator>>(FILE* fd)
	{
		int vectorSize = sizeof(_vector) / sizeof(_vector[0]);

		if (fd = fopen("vector.txt", "w") == NULL)
		{
			std::cout << "Не вдалося відкрити файл!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < vectorSize; i++)
		{
			if (!fprintf(fd, "%lf", (double)_vector[i]))
			{
				std::cout << "Не вийшло переписати вектор до файлу!" << std::endl;
				exit(0);
			}
		}
		fclose(fd);
	}
	vector operator<<(FILE* fd)
	{
		int vectorSize = sizeof(_vector) / sizeof(_vector[0]);

		if (fd = fopen("vector.txt", "r") == NULL)
		{
			std::cout << "Не вдалося відкрити файл!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < vectorSize; i++)
		{
			fscanf(fd, "%lf", (double)_vector[i]);
		}
		fclose(fd);
	}
	T GetMaximumAbs()
	{
		int vectorSize = sizeof(_vector) / sizeof(_vector[0]);
		T maximum = abs(_vector[0]);
		for (int i = 1; i < vectorSize; i++)
		{
			if (abs(_vector[i]) > maximum)
			{
				maximum = abs(_vector[i]);
			}
		}
		return maximum;
	}
	int SetVectorElement(int i, T elementToSet)
	{
		if (i<0 || i>_vectorSize)
		{
			std::cout << "Ви передали некоректне значення елементу вектора!" << std::endl;
			return -1;
		}
		else
		{
			_vector[i] = elementToSet;
		}
		return 0;
	}
	int GetVectorElement(int i)
	{
		if (i<0 || i>_vectorSize)
		{
			std::cout << "Ви передали некоректне значення елементу вектора!" << std::endl;
			return -1;
		}
		else
		{
			return _vector[i];
		}
		return 0;
	}
	int GetVectorSize()
	{
		return _vectorSize;
	}
	void Print()
	{
		for (int i = 0; i < _vectorSize; i++)
		{
			std::cout << _vector[i] << " ";
		}
	}
protected:
	T* _vector;
	int _vectorSize;
};