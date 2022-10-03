import java.util.HashMap;

public class ParenthesisBalanced {

    public static void main(String[] args) {
        String str = "[[{{()()}}]]";
        System.out.println(isBalanced(str) ? "Balanced" : "Not balanced");
    }

    private static boolean isBalanced(String str) {
        HashMap<Character, Integer> hm = new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            char openingBracket = '\0';
            switch (ch) {
                case ']':
                case '[':
                    openingBracket = '[';
                    break;

                case '}':
                case '{':
                    openingBracket = '{';
                    break;

                case ')':
                case '(':
                    openingBracket = '(';
                    break;
            }

            if (openingBracket != '\0') {
                Integer count = hm.get(openingBracket);
                if (count == null) {
                    if (ch == ']' || ch == '}' || ch == ')') {
                        return false;
                    } else {
                        hm.put(openingBracket, 1);
                    }
                } else {
                    switch (ch) {
                        case ']':
                        case '}':
                        case ')':
                            if (count == 1) {
                                hm.remove(openingBracket);
                            } else {
                                hm.put(openingBracket, count - 1);
                            }
                            break;

                        case '[':
                        case '{':
                        case '(':
                            hm.put(openingBracket, count + 1);
                            break;
                    }
                }
            }
        }
        return hm.size() == 0;
    }
}
