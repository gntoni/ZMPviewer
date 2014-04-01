#ifndef GAUGES_H
#define GAUGES_H

typedef struct
{
    double xpos;
    double ypos;
    int channel;
    double K_calib;
    float force;
}Tgauge;

typedef std::vector<Tgauge> TGauges;


#endif // GAUGES_H
