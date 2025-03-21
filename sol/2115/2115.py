from collections import defaultdict

class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        availables = frozenset(supplies)
        n = len(recipes)
        indeg = [0] * n
        leadsTo = defaultdict(list)
        canMake = []
        for i in range(n):
            for ing in ingredients[i]:
                if ing in availables:
                    continue
                indeg[i] += 1
                leadsTo[ing].append(i)
            if indeg[i] == 0:
                canMake.append(i)
        products = []
        while len(canMake) != 0:
            target = recipes[canMake.pop()]
            products.append(target)
            for newIdx in leadsTo[target]:
                indeg[newIdx] -= 1
                if indeg[newIdx] == 0:
                    canMake.append(newIdx)
        return products
