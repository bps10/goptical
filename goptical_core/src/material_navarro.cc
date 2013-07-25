/*

      This file is part of the Goptical Core library.
  
      The Goptical library is free software; you can redistribute it
      and/or modify it under the terms of the GNU General Public
      License as published by the Free Software Foundation; either
      version 3 of the License, or (at your option) any later version.
  
      The Goptical library is distributed in the hope that it will be
      useful, but WITHOUT ANY WARRANTY; without even the implied
      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
      See the GNU General Public License for more details.
  
      You should have received a copy of the GNU General Public
      License along with the Goptical library; if not, write to the
      Free Software Foundation, Inc., 59 Temple Place, Suite 330,
      Boston, MA 02111-1307 USA
  
      Copyright (C) 2010-2011 Free Software Foundation, Inc
      Author: Alexandre Becoulet

*/

#include <Goptical/Material/Navarro>

namespace _Goptical {

  namespace Material {

    Navarro::Navarro()
    {
    }

    Navarro::Navarro(double n1, double n2, double n3, double n4)
      : _n1(n1), _n2(n2), _n3(n3), _n4(n4)
    {
    }

    double Navarro::Herzberger(double wavelen, double A, double B, double C, double D) const
    {
      double w2 = Math::square(wavelen);

      return (+ A
              + B * w2
              + C / (w2 - 0.028)
              + D / Math::square(w2 - 0.028)
              );
    }

    double Navarro::get_measurement_index(double wavelen) const
    {
      double wl = wavelen / 1000.0;
      double a1, a2, a3, a4;

      a1 = Herzberger(wl, 0.66147196, -0.40352796, -0.2804679, 0.03385979);
      a2 = Herzberger(wl, -4.20146383, 2.73508956,  1.50543784, -0.11593235);
      a3 = Herzberger(wl, 6.29834237, -4.69409935, -1.5750865, 0.10293038);
      a4 = Herzberger(wl, -1.75835059, 2.36253794, 0.35011657, -0.02085782);

      return a1 * _n1 + a2 * _n2 + a3 * _n3 + a4 * _n4;
    }

  }

}
