/*

1079. Letter Tile Possibilities

You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

*/

class Solution {
private:
    int res = 0;

    void number(std::string tiles, int level) {
        res++;

        for (int i = level; i < tiles.size(); ++i) {
            if (i != level && tiles[i] == tiles[level]) {
                continue;
            }

            std::swap(tiles[i], tiles[level]);
            number(tiles, level + 1);
        }
    }
public:
    int numTilePossibilities(string tiles) {
        std::sort(tiles.begin(), tiles.end());
        number(tiles, 0);
        return res - 1;
    }
};