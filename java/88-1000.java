import java.util.Map;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;
import java.util.concurrent.TimeUnit;
import java.util.HashMap;

public class Main {
static final double EPS = 1e-6;
static final int NUM = 8;
static final int TARGET = 1000;

static double[] A = new double[NUM];
static String[] res_str = new String[NUM];
static Set<String> ans = new HashSet<String>();
static int times = 0;

public static boolean dfs(int n) {
    // 退出条件
    if (n == 1) {
        if (Math.abs(A[0] - TARGET) < EPS) {
            // System.out.println(res_str[0]);
            ans.add(res_str[0]);
        }
    }

    double a, b;
    String expa, expb;
    Map<Integer, Integer> hash = new HashMap<Integer, Integer>();
    hash.clear();

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            times++;
            // 保存状态（操作数i,j）
            a = A[i];
            b = A[j];
            expa = res_str[i];
            expb = res_str[j];

            // hash判重
            if (hash.get(a) == b) continue;
            if (hash.get(b) == a) continue;
            hash.put(a, b);

            // 改变状态
            A[j] = A[n - 1];
            res_str[j] = res_str[n - 1];

            // +
            A[i] = a + b;
            res_str[i] = '(' + expa + '+' + expb + ')';
            if (dfs(n - 1)) return true;

            // -
            A[i] = a - b;
            res_str[i] = '(' + expa + '-' + expb + ')';
            if (dfs(n - 1)) return true;

            // - 反方向
            A[i] = b - a;
            res_str[i] = '(' + expb + '-' + expa + ')';
            if (dfs(n - 1)) return true;

            // *
            A[i] = a * b;
            res_str[i] = '(' + expa + '*' + expb + ')';
            if (dfs(n - 1)) return true;

            // /
            if (b != 0) {
                A[i] = a / b;
                res_str[i] = '(' + expa + '/' + expb + ')';
                if (dfs(n - 1)) return true;
            }

            // /反方向
            if (a != 0) {
                A[i] = b / a;
                resStr[i] = '(' + expb + '/' + expa + ')';
                if (dfs(n - 1)) return true;
            }

            // 合并
            if (expa.indexOf("(") == -1 &&
                expb.indexOf("(") == -1 && b == NUM) {
                A[i] = a * 10 + b;
                resStr[i] = expa + expb;
                if (dfs(n - 1)) return true;
            }

            // 恢复状态, 回溯过程
            A[i] = a;
            A[j] = b;
            resStr[i] = expa;
            resStr[j] = expb;
        }
    }
    return false;
}

    public static void main(String[] args) {
        for (int i = 0; i < NUM; i++) {
            A[i] = 8;
            res_str[i] = String.format("%.0f", A[i]);
        }
        System.out.println("start searching....");
        long start = System.currentTimeMillis();
        dfs(NUM);
        for (it = ans.iterator(); it.hasNext(); ) {
            System.out.println(it.next());
        }
        long duration = System.currentTimeMillis() - start;
        System.out.println("found : " + ans.size() + " expressions!");
        System.out.println("spend : " + duration + " ms");
    }
}
