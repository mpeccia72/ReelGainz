
#define nodePtr ReelNode*

enum class Item {
    GREEN_LUMBERJACK_PORK,
    BLUE_LUMBERJACK_PORK,
    CORPORATE_PORK,
    WILD,
    HARD_HAT,
    BUZZSAW
};

struct ReelNode {
    nodePtr prev = nullptr;
    nodePtr up = nullptr;
    nodePtr down = nullptr;
    nodePtr left = nullptr;
    nodePtr right = nullptr;
    Item item = Item::BUZZSAW;
};

class ReelTable {

    public:
        ReelTable(); 
        void printTable();

    private:

        // single instance exists in data segment and is ready at compile time
        static constexpr int width = 5;
        static constexpr int height = 3;
        const int maxArea = width * height;

        // 2d table array
        nodePtr table[width][height];

        // helper funtions
        void buildTable(); 

};