#include <iostream>
#include <random>

class Bear {
public:
	Bear() = default;
	Bear(bool _is_hungry, bool _is_tired, bool _is_winter, bool _river_is_close, bool _just_has_eaten_honey);

	void Eat();
	void Sleep();
	void Run_away_from_bees();

	bool is_hungry;
	bool is_tired;
	bool river_is_close;
	bool is_winter;
	bool just_has_eaten_honey;

private:
	void eat_honey_();
	void eat_fish_();
};

Bear::Bear(bool _is_hungry, bool _is_tired, bool _is_winter, bool _river_is_close, bool _just_has_eaten_honey) {
	is_hungry = _is_hungry;
	is_tired = _is_tired;
	river_is_close = _river_is_close;
}

void Bear::Eat() {
	if (river_is_close) {
		eat_fish_();
	}
	else {
		eat_honey_();
	}
	is_hungry = false;
}

void Bear::Sleep() {
	if (is_winter) {
		std::cout << "Ah, again winter. I will chill out after this exhausting year!" << std::endl;
		is_winter = false;
		return;
	}
	std::cout << "This whas a really hard day!, (yawning)" << std::endl;
	is_tired = false;
}

void Bear::Run_away_from_bees() {
	std::cout << "Again these boring creatures!" << std::endl;
	just_has_eaten_honey = false;
}

void Bear::eat_honey_() {
	std::cout << "What a delicious honey! Neam, neam!" << std::endl;
	just_has_eaten_honey = true;
}

void Bear::eat_fish_() {
	std::cout << "I love fish of this river! yummy!" << std::endl;
}


int main() {
	int n;
	std::cin >> n;
	Bear* B = new Bear[n];
	for (int i = 0; i < n; i++) {
		B[i].is_hungry=rand()%2;
		B[i].is_tired=rand()%2;
		B[i].river_is_close=rand() % 2;
		B[i].is_winter=rand() % 2;
		B[i].just_has_eaten_honey=rand() % 2;

		if (B[i].is_hungry) {
			B[i].Eat();
		}
		if (B[i].is_tired || B[i].is_winter) {
			B[i].Sleep();
		}
		if (B[i].just_has_eaten_honey) {
			B[i].Run_away_from_bees();
		}

		std::cout << B[i].is_hungry << " " << B[i].is_tired << " " << B[i].river_is_close <<
			" " << B[i].is_winter << " " << B[i].just_has_eaten_honey << std::endl;
	}
	
	delete[] B;
	system("pause");
	return 0;
}
