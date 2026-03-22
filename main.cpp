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
    context->move_to(0.0, 0.0);
    context->line_to(50., 50.);
    const double radius = 30.0;
    context->arc(50., 50., radius, 0.0, 2. * std::numbers::pi);
    context->close_path();
    context->fill();
    context->set_line_width(1.0);
    context->stroke();
    context->set_source_rgba(0.5, 0.2, 0.5, .8);
    context->move_to(100., 100.);
    context->rotate(std::numbers::pi);
    context->rectangle(100., 100., 100., 100.);
    context->fill();
    context->stroke();
    surface->write_to_png("test.png");
  } catch (Cairo::logic_error &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
