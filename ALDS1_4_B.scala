import scala.io.StdIn

object Main {
  def main(args: Array[String]): Unit = {
    val n = StdIn.readLine.toInt
    val S = StdIn.readLine.split(' ').map(_.toInt)
    val q = StdIn.readLine.toInt
    val T = StdIn.readLine.split(' ').map(_.toInt)
    val C = new Array[Int](100000)
    var len = 0

    val res = T filter { m => binSearch(S, n, m) }
    println(res.length)
  }

  def binSearch(S: Array[Int], len: Int, i: Int): Boolean = {
    var l = 0
    var r = len
    while (l < r) {
      val indice = (r + l) / 2
      if (S(indice) < i) {
        l = indice + 1
      } else if (S(indice) > i) {
        r = indice
      } else {
        return true
      }
    }
    false
  }
}
