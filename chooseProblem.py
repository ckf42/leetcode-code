import pathlib
import random

README_PATH = './README.md'

def main() -> None:
    numList: list[int] = []
    with pathlib.Path(pathlib.Path(__file__).parent / README_PATH)\
            .resolve(strict=True).open('rt', encoding='utf-8') as f:
        for line in f:
            if len(line) > 0 and line[0].isdigit():
                numList.extend((int(x) for x in line.split()))
    print(random.choice(numList))

if __name__ == '__main__':
    main()

