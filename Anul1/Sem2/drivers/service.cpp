#include "service.h"

service::service(repo &r): re(r) {}

void service::add(const std::string& name, int number, int wins)
{
   if(number <= 0 || wins < 0)
       throw std::runtime_error("must be positive");
   Driver d{name, number, wins};
   this->re.add(d);
}

void service::remove(int number)
{
    if(number <= 0)
       throw std::runtime_error("must be positive");
    this->re.remove(number);
}

void service::update(const std::string& name, int number, int wins)
{
    if(number <= 0 || wins < 0)
        throw std::runtime_error("must be postive");
    this->re.update(name, number, wins);
}

int service::getSize() const
{
    return this->re.getSize();
}

std::vector<Driver>& service::getAll()
{
    return this->re.getAll();
}

std::vector<Driver> service::filter(int wins)
{
    std::vector<Driver> result;
    int n = this->re.getSize();
    std::vector<Driver>& e = this->re.getAll();
    for (int i = 0; i < n; i++)
    {
        if(e[i].getWins() >= wins)
            result.push_back(e[i]);
    }
    return result;
}
