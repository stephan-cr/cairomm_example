#include "cairomm/context.h"
#include "cairomm/enums.h"
#include "cairomm/surface.h"
#include "cairomm/exception.h"

#include <iostream>
#include <numbers>

int main()
{
  try {
    auto surface =
      Cairo::ImageSurface::create(Cairo::Surface::Format::ARGB32, 200, 200);
    auto context = Cairo::Context::create(surface);
    context->set_antialias(Cairo::ANTIALIAS_DEFAULT);
    context->set_source_rgba(0.3, 0.2, 0.5, 1.0);
    context->set_line_width(2.0);
    for (int i = 0; i < 20; i++) {
      context->move_to(0., 10. * static_cast<double>(i));
      for (int j = 0; j < 10; j++) {
        context->rel_line_to(10., 10.);
        context->rel_line_to(10., -10.);
      }
    }
    context->stroke();
    context->set_source_rgba(0.3, 0.2, 0.5, .5);
    context->arc(100., 100., 100., 0., 2. * std::numbers::pi);
    context->fill();
    surface->write_to_png("test.png");
  } catch (Cairo::logic_error &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
