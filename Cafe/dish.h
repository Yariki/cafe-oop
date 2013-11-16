#include<string>

class Dish : public ICafeObject, public ICafeObject
{
public:
	Ingredient *m_Ingredient;
	Dish(void);
    Dish(std::string name, double cost = 0);
    ~Dish(void);

    void setName(std::string name);
    std::string getName() const;
    void setCost(double cost);
    double getCost() const;

    friend bool operator==(const Dish& left, const Dish& right)
    {
		if(left.getCost() == right.getCost() && left.getName() == right.getName()) return true; 
		else return false;
    }

private:
	std::string name_;
    double cost_;
	map<BaseIngredient*,double> ingridients_;
};