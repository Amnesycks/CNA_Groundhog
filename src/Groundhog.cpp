/*
** EPITECH PROJECT, 2020
** CNA
** File description:
** Groundhog
*/

#include "../include/Groundhog.hpp"

Groundhog::Groundhog()
{
    _switches = 0;
    _tempIncreaseAverage = 0;
    _relativeTempEvolution = 0;
    _lastRelativeTempEvolution = 0;
    _isIncrease = false;
    _standardDeviation = 0;
}

Groundhog::~Groundhog()
{
}

void Groundhog::calculateTemperatureIncreaseAverage(unsigned int period)
{
    double tmp = 0;

    if (_vec.size() <= period)
        return;
    _tempIncreaseAverage = 0;
    for (size_t i = _vec.size() - period; i != _vec.size(); i++) {
        tmp = _vec[i] - _vec[i - 1];
        if (tmp > 0)
            _tempIncreaseAverage += tmp;
    }
    _tempIncreaseAverage /= period;
}

void Groundhog::calculateRelativeTemperatureEvolution(unsigned int period)
{
    double val1 = 0;
    double val2 = 0;

    if (_vec.size() <= period)
        return;
    _lastRelativeTempEvolution = _relativeTempEvolution;
    val1 = _vec[_vec.size() - period - 1];
    val2 = _vec.back();
    _relativeTempEvolution = int (round((val2 - val1) /val1 * 100));
}

void Groundhog::calculateStandardDeviation(int period)
{
    double val1 = 0;
    double val2 = 0;

    for (auto i = _vec.end() - period; i != _vec.end(); ++i) {
        val1 += *i;
        val2 += (*i) * (*i);
    }
    _standardDeviation = sqrt(val2 / period - (val1 / period) * (val1 / period));
}

void Groundhog::calculateWeirdest(void)
{
    size_t i = _vec.size() - 1;
    if (_standardDeviation != 0 && fabs(_vec[i] - _vec[i - 1]) - 2 * _standardDeviation > 0) {
        _weirdValues.push_back(_vec[i]);
    }
}

void Groundhog::display(unsigned int period)
{
    std::cout << std::fixed << std::setprecision(2) << "g=";
    if (_vec.size() <= period)
        std::cout << "nan";
    else
        std::cout << _tempIncreaseAverage;

    std::cout << "\tr=";
    if (_vec.size() <= period)
        std::cout << "nan";
    else
        std::cout << std::fixed << std::setprecision(3) <<  _relativeTempEvolution;
    std::cout << "%";

    std::cout <<"\ts=";
    if (_vec.size() < period)
        std::cout << "nan";
    else
        std::cout << std::fixed << std::setprecision(2) << _standardDeviation;
            int tendencyDown = 0;
            int tendencyUp = 0;
            if (_vec.size() == period) {
                for (auto it = _vec.end() - 1;  it != _vec.end() - period - 1; --it) {
                    (*it - *(it - 1) > 0) ? ++tendencyUp: ++tendencyDown;
                }
                _isIncrease = (tendencyUp == true) ? false : true;
            }
            if (_vec.size() > period) {
            for (auto it = _vec.end() - 1;  it != _vec.end() - period; --it) {
                (*it - *(it - 1) > 0) ? ++tendencyUp: ++tendencyDown;
            }
            if ((_vec.size() > period + 1) && (
            (_isIncrease && tendencyDown > tendencyUp) ||
            (!_isIncrease && tendencyUp > tendencyDown))) {
                std::cout << "\ta switch occurs";
                _switches +=1;
                _isIncrease = (_isIncrease == true) ? false : true;
            }
        }
    std::cout << std::endl;
}

void Groundhog::core(int period)
{
    int nbLine = 0;
    bool isEOF = true;

    std::cout << std::fixed << std::setprecision(2);
    while (std::scanf("%s", _input) != EOF) {
        if (std::strcmp("STOP", _input) == 0) {
            isEOF = false;
            break;
        }
        if (std::atof(_input) != 0) {
            _vec.push_back(std::atof(_input));
            calculateWeirdest();
            calculateTemperatureIncreaseAverage(period);
            calculateRelativeTemperatureEvolution(period);
            calculateStandardDeviation(period);
            display(period);
        }
        nbLine++;
    }
    if (nbLine < period || isEOF == true)
        exit(84);
    std::cout << "Global tendency switched " <<_switches << " times" << std::endl;
    std::cout << "5 weirdest values are [";
    for (auto const &it : _weirdValues) {
        std::cout << std::setprecision(1) << it;
        if (it != _weirdValues.back())
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
