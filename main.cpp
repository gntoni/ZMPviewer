#include "zmpview.h"
#include <QApplication>
#include <vector>
#include <comedilib.h>
#include <limits>
#include <pthread.h>

int main(int argc, char *argv[])
{
    TGauges Gauges;

    QApplication a(argc, argv);
    zmpview w(&Gauges);
    w.show();

    //comedi variables
    comedi_t *it;
    lsampl_t data;
    comedi_range *range_t;
    int retval;
    unsigned int i=0;
    int subdev=0;
    int range=1;
    int aref = AREF_GROUND;

    it = comedi_open("/dev/comedi0");
    if(it == NULL)
    {
      comedi_perror("comedi_open");
      return -1;
    }
    range_t=comedi_get_range(it,0,0,range);
    while(1)
    {
        if (Gauges.size()>=1)
        {
          for(i=1;i<Gauges.size();i++)
          {
            retval = comedi_data_read(it, subdev, Gauges[i].channel, range, aref, &data);
            if(retval < 0)
            {
              comedi_perror("comedi_data_read");
              return -1;
            }
            Gauges[i].force=(float)comedi_to_phys(data,range_t,std::numeric_limits<unsigned short int>::max());
            Gauges[i].force=Gauges[i].force*Gauges[i].K_calib;
            usleep(100000);
          }
        }
    }

    return a.exec();
}
