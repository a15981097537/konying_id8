#include <iostream>
#include "Core"
#include <Dense>
#include <complex>
#include <cmath>
#include <math.h>
#include <cfloat>
#include <equation.h>

//void quadratic2quartic(Eigen::Matrix<double, 6, 1> & _par1,
//                     Eigen::Matrix<double, 6, 1> & _par2,
//                     Eigen::Matrix<double, 5, 1> & _y2x_par,
//                     Eigen::Matrix<std::complex<double>, 5, 1> &_quartic_par)
//{
//  double A, B, C, D, E;
//  double a1, b1, c1, d1, e1, f1, a2, b2, c2, d2, e2, f2;

//  a1 = _par1[0];
//  b1 = _par1[1];
//  c1 = _par1[2];
//  d1 = _par1[3];
//  e1 = _par1[4];
//  f1 = _par1[5];

////   std::cout  << a1 << "   " << b1 <<  "   " <<  c1  << "   " << d1 <<  "   " << e1 <<  "   " << f1 << std::endl;

//  a2 = _par2[0];
//  b2 = _par2[1];
//  c2 = _par2[2];
//  d2 = _par2[3];
//  e2 = _par2[4];
//  f2 = _par2[5];

////   std::cout  << a2 << "   " << b2 <<  "   " <<  c2  << "   " << d2 <<  "   " << e2 <<  "   " << f2 << std::endl;


//  A = a1*c2 - c1*a2;
//  B = b1*c2 - c1*b2;
//  C = d1*c2 - c1*d2;
//  D = e1*c2 - c1*e2;
//  E = f1*c2 - c1*f2;
//  _y2x_par << A, B, C, D, E;
////   std::cout << "A-E: \n";
////   std::cout << A << "   " << B << "   " << C <<"   " << D << "   " << E << std::endl;

//  double M0, M1, M2, M3, M4;
//  M4 = a1*B*B - b1*A*B + c1*A*A;
//  M3 = 2*a1*B*D - b1*A*D - b1*B*C + 2*c1*A*C + d1*B*B - e1*A*B;
//  M2 = a1*D*D - b1*C*D - b1*B*E + c1*C*C + 2*c1*A*E + 2*d1*B*D - e1*A*D - e1*B*C + f1*B*B;
//  M1 = -b1*D*E + 2*c1*C*E + d1*D*D - e1*C*D - e1*B*E + 2*f1*B*D;
//  M0 = c1*E*E - e1*D*E + f1*D*D;
////   std::cout << "m4-m0: \n";
////   std::cout << M4 << "   " << M3 << "   " << M2 << "   " << M1 << "   " << M0 << std::endl;
////
//  double b, c, d, e;
//  b = M3 / M4;
//  c = M2 / M4;
//  d = M1 / M4;
//  e = M0 / M4;
////   std::cout  << "b, c, d, e: \n";
////   std::cout  << " " << b << "   " << c << "   " << d<< "   " << e << "   \n";
//  _quartic_par << 1.0, b, c, d, e;

//}

////extract a root
//void sqrtn(const std::complex<double> &_input, double n,
//          std::complex<double> &_out)
//{
////   double r = sqrt(_input.real()*_input.real() + _input.imag()*_input.imag());
////   std::cout << _input << std::endl;
//  double r = hypot(_input.real(), _input.imag());
////   std::cout << "the norm is " << r << std::endl;
//  if(r > 0.0)
//  {
//    double a = atan2(_input.imag(), _input.real());
////     std::cout << "the a is: " << a << std::endl;

////     double a = arg(_input);
//    n = 1 / n;
//    r = pow(r, n);
//    a *= n;
////    _out.real() = r * cos(a);
////    _out.imag() = r * sin(a);
//    _out.real(r * cos(a));
//    _out.imag(r * sin(a));
//  }
//  else
//  {
////    _out.real() = 0.0;
////    _out.imag() = 0.0;
//    _out.real(0.0);
//    _out.imag(0.0);
//  }
////   std::cout << "out :" << _out << std::endl;
//}

//void Ferrari(Eigen::Matrix<std::complex<double>, 5, 1> & _quartic_par,
//                 Eigen::Matrix<std::complex<double>, 4, 1> & _x)
//{
//  std::complex<double> a = _quartic_par[0];
//  std::complex<double> b = _quartic_par[1];
//  std::complex<double> c = _quartic_par[2];
//  std::complex<double> d = _quartic_par[3];
//  std::complex<double> e = _quartic_par[4];

//  std::complex<double> P = (c*c + 12.0*e - 3.0*b*d) / 9.0;
//  std::complex<double> Q = (27.0*d*d + 2.0*c*c*c + 27.0*b*b*e - 72.0*c*e - 9.0*b*c*d) / 54.0;
////   std::cout << "P: " << P << "   \nQ: " << Q << std::endl;
//  std::complex<double> D, u, v;
////   D = cabs(sqrt(Q*Q - P*P*P));

//  sqrtn(Q*Q - P*P*P, 2.0, D);
////   std::cout << "D: " << D << std::endl;
//  u = Q + D;
//  v = Q - D;
////   std::cout << "u: " << u << "  \nv: " << v << std::endl;
//  if(v.real()*v.real() + v.imag()*v.imag() > u.real()*u.real() + u.imag()*u.imag())
//  {
//    sqrtn(v, 3.0, u);
//  }
//  else
//  {
//    sqrtn(u, 3.0, u);
//  }
////   std::cout <<"u: " << u << std::endl;
//  std::complex<double> y;
//  if(u.real()*u.real() + u.imag()*u.imag() > 0.0)
//  {
//    v = P / u;
//    std::complex<double> o1(-0.5,+0.86602540378443864676372317075294);
//    std::complex<double> o2(-0.5,-0.86602540378443864676372317075294);
//    std::complex<double> &yMax = _x[0];
//    double m2 = 0.0;
//    double m2Max = 0.0;
//    int iMax = -1;

//    for(int i = 0; i < 3; ++i)
//    {
//      y = u + v + c / 3.0;
//      u *= o1;
//      v *= o2;
//      a = b*b + 4.0*(y-c);
//      m2 = a.real()*a.real() + a.imag()*a.imag();

//      if(0==i || m2Max < m2)
//      {
//    m2Max = m2;
//    yMax = y;
//    iMax = i;
//      }
//    }
//    y = yMax;
//  }
//  else
//  {//cubic equation
//    y = c / 3.0;
//  }
//  std::complex<double> m;
//  sqrtn(b*b + 4.0*(y-c), 2.0, m);
//  if(m.real()*m.real() + m.imag()*m.imag() >= DBL_MIN)
//  {
//    std::complex<double> n = (b*y - 2.0*d) / m;
//    sqrtn((b+m)*(b+m) - 8.0*(y+n), 2.0, a);
//    _x[0] = (-(b+m) + a) / 4.0;
////     std::cout << "_x[0]: " << _x[0] << std::endl;
//    _x[2] = (-(b+m) - a) / 4.0;
////     std::cout << "_x[1]: " << _x[1] << std::endl;
//    sqrtn((b-m)*(b-m) - 8.0*(y-n), 2.0, a);
//    _x[1] = (-(b-m) + a) / 4.0;
//    _x[3] = (-(b-m) -a) / 4.0;
////     std::cout << "_x[2]: " << _x[2] << std::endl;
////     std::cout << "_x[3]: " << _x[3] << std::endl;
//  }
//  else
//  {
//     sqrtn(b*b - 8.0*y, 2.0, a);
//     _x[0] = _x[1] = (-b + a) / 4.0;
//     _x[2] = _x[3] = (-b - a) / 4.0;
//  }

////   for(int i = 0; i <4; i++)
////   {
////     std::cout << _x[i] << std::endl;
////   }
//}

//void compute_y(Eigen::Matrix<std::complex<double>, 4, 1> &_x,
//           Eigen::Matrix<double, 5, 1> &_y2x_par,
//           Eigen::Matrix<std::complex<double>, 4, 1> &_y)
//{
//  for(int i = 0; i < 4; i++)
//  {
//    _y[i] = (-_y2x_par[0]*_x[i]*_x[i] - _y2x_par[2]*_x[i] - _y2x_par[4]) / (_y2x_par[1]*_x[i] + _y2x_par[3]);
////     std::cout << "_y[" << i << "]" << _y[i] << std::endl;
//  }
//}

//int equation_test( Eigen::Matrix<double, 6, 1> ic1, Eigen::Matrix<double, 6, 1>ic2,short *x_point,short *y_point) {
////  Eigen::Matrix<double, 6, 1> ic1, ic2;
////  ic1 <<414181, -12635.8, 398758, -9.53484e+08, -4.16931e+08, 5.00382e+11;
////  ic2 << 923938, -41764.7, 932015, -2.10858e+09, -9.79279e+08, 6.2537e+11;
////  ic1 <<1, 1, 1, 1, 1, 4;
////  ic2 <<1, 5, 1, 1, 1, 1;

//  Eigen::Matrix<std::complex< double >, 5, 1> quartic_par;
//  Eigen::Matrix<double, 5, 1> y2x_par;
////   quadratic2quartic(ic1, ic2, quartic_par);
//  quadratic2quartic(ic1, ic2, y2x_par, quartic_par);
//  Eigen::Matrix<std::complex< double >, 4, 1> x, y;
//  Ferrari(quartic_par, x);
//  compute_y(x, y2x_par, y);
//  std::cout <<"the result :" << std::endl;
//  for(int i = 0; i < 4; i++)
//  {
//    std::cout << "x: " << x[i] <<  "\ty: " << y[i] << std::endl;
//    if(-1000<x[i].real()&&x[i].real()<1000&&
//       -1000<y[i].real()&&y[i].real()<1000){
//        x_point[i]=x[i].real();
//        y_point[i]=y[i].real();
//    }
//    else
//    {
//        x_point[i]=1000;
//        y_point[i]=1000;
//    }
//  }

////     std::cout << "Hello, world!" << std::endl;

//    return 0;
//}


bool equationProcess(){

}






