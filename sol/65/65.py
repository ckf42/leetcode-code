import re

class Solution:
    intPatt = r'[+-]?\d+'
    decPatt = r'[+-]?(?:\d+\.\d*|\.\d+)'
    wholePatt = re.compile(f'^(?:(?:{intPatt})|(?:{decPatt}))(?:[eE]{intPatt})?$')

    def isNumber(self, s: str) -> bool:
        return self.wholePatt.match(s) is not None
