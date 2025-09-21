import heapq as hq

class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.table = dict()
        self.movies = dict()
        for s, m, p in entries:
            self.table[(s, m)] = p
            if m not in self.movies:
                self.movies[m] = list()
            self.movies[m].append([p, s, True])
        for m in self.movies:
            self.movies[m].sort()
        self.rented = set()
        self._lazyMovies = {m: False for m in self.movies.keys()}
        self._lastReport = []
        self._lastSearch = {m: [] for m in self.movies.keys()}

    def rent(self, shop: int, movie: int) -> None:
        self.rented.add((self.table[(shop, movie)], shop, movie))
        self._lazyMovies[movie] = True
        self._lastReport.clear()
        self._lastSearch[movie].clear()

    def drop(self, shop: int, movie: int) -> None:
        self.rented.remove((self.table[(shop, movie)], shop, movie))
        self._lazyMovies[movie] = True
        self._lastReport.clear()
        self._lastSearch[movie].clear()

    def search(self, movie: int) -> List[int]:
        if movie not in self.movies:
            return []
        if len(self._lastSearch[movie]) == 0:
            if self._lazyMovies[movie]:
                for i, (p, s, _) in enumerate(self.movies[movie]):
                    self.movies[movie][i][2] = (p, s, movie) not in self.rented
                self._lazyMovies[movie] = False
            self._lastSearch[movie] = [
                s
                for _, s in hq.nsmallest(
                    5,
                    ((p, s) for p, s, inShop in self.movies[movie] if inShop)
                )
            ]
        return self._lastSearch[movie]

    def report(self) -> List[List[int]]:
        if len(self._lastReport) == 0:
            self._lastReport = [(s, m) for _, s, m in hq.nsmallest(5, self.rented)]
        return self._lastReport


