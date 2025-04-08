#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/color.hpp"
#include <string>

using namespace ftxui;

ButtonOption ButtonStyle(Color color) {
  auto option = ButtonOption::Animated(color);
  option.transform = [](const EntryState &s) {
    auto element = text(s.label);
    if (s.focused) {
      element |= bold;
    }
    return element | center | borderEmpty | flex;
  };
  return option;
}

int main() {
  int value = 50;

  auto screen = ScreenInteractive::FitComponent();
  // The tree of components. This defines how to navigate using the keyboard.
  auto buttons = Container::Vertical(
      {Container::Horizontal({
           Button(
               "Decrease", [&] { value--; }, ButtonStyle(Color::Red)),
           Button(
               "Reset", [&] { value = 50; }, ButtonStyle(Color::Green)),
           Button(
               "Increase", [&] { value++; }, ButtonStyle(Color::Blue)),
       }),
       Button("Close", screen.ExitLoopClosure(),
              ButtonStyle(Color::GrayDark))});

  // Modify the way to render them on screen:
  auto component = Renderer(buttons, [&] {
    return vbox({vbox({
                     text("value = " + std::to_string(value)),
                     separator(),
                     gauge(value * 0.01f),
                 }) | border,
                 buttons->Render()});
  });

  screen.Loop(component);
  return 0;
}
