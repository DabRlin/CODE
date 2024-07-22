class LexicalAnalyzer:
    def __init__(self, source_code):
        self.source_code = source_code
        self.position = 0

    def read_char(self):
        if self.position < len(self.source_code):
            char = self.source_code[self.position]
            self.position += 1
            return char
        return None

    def analyze(self):
        while True:
            char = self.read_char()
            if char is None:
                break
            if char.isspace():
                continue
            if char.isalpha():
                self.handle_letter(char)
            elif char.isdigit():
                self.handle_number(char)
            elif char in ('+', '-', '*', '/', '=', ';', ',', '(', ')', '{', '}', '>', '<'):
                self.handle_operator_or_delimiter(char)
            else:
                self.handle_error(char)

    def handle_letter(self, char):
        word = char
        while True:
            char = self.read_char()
            if char is None or not char.isalnum():
                self.position -= 1
                break
            word += char
        if word in ('if', 'else', 'while', 'return', 'int'):  # 添加更多关键字
            print(f'关键字: {word}')
        else:
            print(f'标识符: {word}')

    def handle_number(self, char):
        number = char
        while True:
            char = self.read_char()
            if char is None or not char.isdigit():
                self.position -= 1
                break
            number += char
        print(f'常数: {number}')

    def handle_operator_or_delimiter(self, char):
        print(f'运算符/分界符: {char}')

    def handle_error(self, char):
        print(f'Error: 未识别的字符 {char}')

# 示例使用
source_code = """
int x = 10;
if (x > 5) {
    return x;
}
"""
analyzer = LexicalAnalyzer(source_code)
analyzer.analyze()
