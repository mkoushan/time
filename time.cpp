#include <iostream>
#include <array>
#include <algorithm>

enum Period{
    AM,
    PM
};

class Time {
    private:

        int hour, min;
        Period period;

    public:
        Time(const int& p_hour, const int& p_min) : hour(p_hour), min(p_min), period(AM) {};
        Time() : hour(12), min(0), period(AM) {
            readTime();
        };

        bool operator<(const Time& other) const {
            return this->getInMinutes() < other.getInMinutes();
        }
        friend std::ostream& operator<<(std::ostream& out, const Time& obj);
        void readTime() {
            int hour, min;
            char period_type[3] = "AM";
            std::cin >> hour >> min >> period_type;
            setHour(hour);
            setMinute(min);
            setPeriod(period_type);
        }

        void setHour(const int& p_hour){
            if(p_hour <= 12 && p_hour >= 0)
                this->hour = p_hour;
            else
                std::cout << "Invalid Argument!" << std::endl;
        }
        void setMinute(const int& p_min){
            if(p_min <= 59 && p_min >= 0)
                this->min = p_min;
            else
                std::cout << "Invalid Argument!" << std::endl;
        }
        void setPeriod(const char* p_period){
            switch(p_period[0])
            {
                case 'a':
                case 'A':
                    this->period = AM;
                    break;

                case 'p':
                case 'P':
                    this->period = PM;
                    break;
                
                default:
                    std::cerr << "Invalid argument!\n";
            }
        }

        int getHour() const { return this->hour; }
        int getMinute() const { return this->min; }
        Period getPeriod() const {return this->period;}
        int getInMinutes() const {return this->hour * 60 + this->min + this->period * 720;}
};

std::ostream& operator<<(std::ostream& out, const Time& obj) {
    out << obj.getHour() << ' ' << obj.getMinute() << ' ' << (obj.getPeriod() == AM ? "AM" : "PM");
    return out;
}

int main(){
    Time m(0, 0);
    std::array <Time, 10> arr;
    
    for (auto& k : arr) 
        m = std::max(m, k);

    std::clog << m;
    return 0; 
} 
