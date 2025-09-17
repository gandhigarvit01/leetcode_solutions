class FoodRatings {
public:
    unordered_map<string, pair<string,int>> foodData;
    unordered_map<string, set<pair<int,string>>> cuisineData;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodData[foods[i]] = {cuisines[i], ratings[i]};
            cuisineData[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodData[food];
        cuisineData[cuisine].erase({-oldRating, food});
        cuisineData[cuisine].insert({-newRating, food});
        foodData[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        return cuisineData[cuisine].begin()->second;
    }
};


/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */