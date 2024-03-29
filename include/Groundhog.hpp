/*
** EPITECH PROJECT, 2020
** CNA
** File description:
** Groundhog
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>

class Groundhog {
    public:
        Groundhog();
        ~Groundhog();
        void core(int period);
        void calculateTemperatureIncreaseAverage(unsigned int period);
        void calculateRelativeTemperatureEvolution(unsigned int period);
        void calculateWeirdest(void);
        void calculateStandardDeviation(int period);
        void display(unsigned int period);
    protected:
    private:
        char _input[100];
        std::vector<double> _vec;
        std::vector<double> _weirdValues;
        double _tempIncreaseAverage;
        int _relativeTempEvolution;
        int _lastRelativeTempEvolution;
        double _standardDeviation;
        int _switches;
        bool _isIncrease;
};

#endif /* !GROUNDHOG_HPP_ */
