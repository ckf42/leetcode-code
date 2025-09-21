class Spreadsheet:

    def __init__(self, rows: int):
        self.vals = dict()

    def setCell(self, cell: str, value: int) -> None:
        self.vals[cell] = value

    def _get(self, cell: str) -> int:
        return self.vals.get(cell, 0)

    def resetCell(self, cell: str) -> None:
        if cell in self.vals:
            del self.vals[cell]

    def _evalRef(self, ref: str) -> int:
        if ref[0].isalpha():
            return self._get(ref)
        return int(ref)

    def getValue(self, formula: str) -> int:
        x, y = formula[1:].split("+")
        return self._evalRef(x) + self._evalRef(y)

