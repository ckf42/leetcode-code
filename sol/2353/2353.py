import heapq as hq

class FoodRatings:

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self._foodProp: dict[str, tuple[str]] = {
            f: (c, -r)
            for f, c, r in zip(foods, cuisines, ratings)
        }
        cs: frozenset[str] = frozenset(cuisines)
        self._ordering: dict[str, list[tuple[int, str]]] = {
            c: list()
            for c in cs
        }
        for f, c, r in zip(foods, cuisines, ratings):
            self._ordering[c].append((-r, f))
        for c in cs:
            hq.heapify(self._ordering[c])

    def changeRating(self, food: str, newRating: int) -> None:
        c, r = self._foodProp[food]
        hq.heappush(self._ordering[c], (-newRating, food))
        self._foodProp[food] = (c, -newRating)

    def highestRated(self, cuisine: str) -> str:
        while True:
            r, f = self._ordering[cuisine][0]
            if r == self._foodProp[f][1]:
                return f
            hq.heappop(self._ordering[cuisine])


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
