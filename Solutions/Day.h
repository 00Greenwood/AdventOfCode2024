#include <string>

// Bass class for the Days.
class Day
{
public:
	explicit Day(int day);
	virtual ~Day() = default;

	std::string name() const;

	enum Part
	{
		PART_1,
		PART_2
	};

	// Solve the Day for a specific part.
	virtual std::string solve(Part) const = 0;

protected:
	std::string input() const;

private:
	// Fetch the input from the Advent of Code website.
	void fetch_input(int day);

	std::string m_name;
	std::string m_input;
};
