import graphlib

class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        availables = set(supplies)
        g = {
            n: ingredients[i]
            for i, n in enumerate(recipes)
        }
        nodeOrder = tuple()
        isDag = False
        while not isDag:
            try:
                nodeOrder = tuple(graphlib.TopologicalSorter(g).static_order())
            except graphlib.CycleError as e:
                for node in e.args[1][:-1]:
                    del g[node]
            else:
                isDag = True
        for ing in nodeOrder:
            if ing not in g:
                continue
            if all(x in availables for x in g[ing]):
                availables.add(ing)
        availables.difference_update(supplies)
        return availables
