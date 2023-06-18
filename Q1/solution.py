import sys


def get_elf_with_highest_calories(file_path):
    with open(file_path, "r") as f:
        current_elf = 1
        current_calories = 0
        highest_elf = (1, 0)
        for line in f:
            if line == "\n":
                if current_calories > highest_elf[1]:
                    highest_elf = (current_elf, current_calories)
                current_calories = 0
                current_elf += 1

            else:
                current_calories += int(line)

        return highest_elf


def main():
    file_path = "input.txt"
    if len(sys.argv) > 2:
        raise Exception("This script accepts only 1 argument")
    elif len(sys.argv) == 2:
        file_path = sys.argv[1]
    print(get_elf_with_highest_calories(file_path))


if __name__ == "__main__":
    main()
