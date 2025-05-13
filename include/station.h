#ifndef station_h
#define station_h

#include <string>
#include <vector> 

class Station {
private:
    int Id_; 
    std::string nAme; 
    std::string CiTy_;

public:
    Station(int a, const std::string& b, const std::string& c); 
    
    int getID() const; 
    std::string GetName() const; 
    std::string getcity() const; 

    void setName(std::string newName); 
    void SetCity(const std::string& City); 

    void Display_Info() const; 
};

#endif
