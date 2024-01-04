#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

class Sum_and_count{
  int m_count{};
  int m_sum{};
  int m_divisor;
  public:
  Sum_and_count(int n=1): m_divisor(n){ }
  int get_sum() const{ return m_sum; }
  int get_count() const{ return m_count; }
  void operator()(const int& elem){
    if( elem % m_divisor == 0){
       m_count++;
       m_sum += elem;
    }
  }
};

int main() {
  //std::cout << "Hello World!\n";
  std::vector<int> v;
  std::string line;
  int n{};
  std::cout<<"[IN]: ";
  getline(std::cin,line);
  std::istringstream iss(line);
  while(iss>>n){
      v.push_back(n);
  }

  int divisor = 3;
  Sum_and_count sum_and_count = std::for_each(v.begin(), v.end(), Sum_and_count(divisor));
  std::cout<<"[OUT]: get_sum() = "<<sum_and_count.get_sum()<<std::endl;
  std::cout<<"[OUT]: get_count() = "<<sum_and_count.get_count()<<std::endl;
  std::cout<<"[OUT]: get_sum() = "<<std::for_each(v.begin(), v.end(), Sum_and_count(divisor)).get_sum()<<std::endl;
  std::cout<<"[OUT]: get_count() = "<<std::for_each(v.begin(), v.end(), Sum_and_count(divisor)).get_count()<<std::endl;
}
