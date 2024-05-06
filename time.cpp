#include <iostream>
#include <array>
#include <algorithm>

class Time {
    private:
        enum Period{
            AM,
            PM
        } period;

        int hour, min;

    public:
        Time() : hour(12), min(0), period(AM) {
            readTime();
        };

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
                this->hour = p_min;
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

        int getHour() const { return hour; }
};

int main(){
    std::array <Time, 10> arr;

    return 0; 
} 
