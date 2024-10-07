#include <Day.h>

class Day0 : public Day {
public:
  explicit Day0();
  virtual ~Day0() = default;

  std::string solve(Part) const override;
};
