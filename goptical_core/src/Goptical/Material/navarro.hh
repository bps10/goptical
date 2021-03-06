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


#ifndef GOPTICAL_MATERIAL_CONRADY_HH_
#define GOPTICAL_MATERIAL_CONRADY_HH_

#include "Goptical/common.hh"

#include "Goptical/Material/dielectric.hh"

namespace _Goptical {

  namespace Material {

    /**
       @short Navarro model for optical glass material
       @header Goptical/Material/Navarro
       @module {Core}
       @main

       This class models optical properties of dielectric
       materials with conrady refractive index dispersion formula.

       Refractive index formula is:

       @math $ n_\lambda = A + \frac{B}{\lambda} + \frac{C}{\lambda^{3.5}} $
       
       with @math $\lambda$ the micrometer wavelength.
     */

    class Navarro : public Dielectric
    {
    public:

      /** Create an empty Navarro model */
      Navarro();

      double Herzberger(double wavelen, double A, double B, double C, double D) const;

      /** Create an Navarro model with given coefficients */
      Navarro(double n1, double n2, double n3, double n4);

      /** Change Navarro constant term */
      inline void set_coefficients(double n1, double n2, double n3, double n4);

      /** @override */
      double get_measurement_index(double wavelen) const;
    private:

      double _n1, _n2, _n3, _n4;
    };

  }
}

#endif

