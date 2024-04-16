#include <string>
#include <utility>

template<typename T> using twin = std::pair<T, T>;

twin<std::string> authors;

template<typename elemType> class ListItem;
template<typename elemType> class List {
    List<elemType>();
    List<elemType>(const List<elemType>&);
    ~List();

    void insert(ListItem<elemType> *ptr, elemType val);

private:
    ListItem<elemType> *front, *end;
};

