import scala.collection.mutable
class Person(val name: String, val age: Int) {
  def greet(): Unit = {
    println(s"Hi, I'm $name and I'm $age years old.")
  }
}

// Usage


object BasicTypes extends App {

def describe(x: Any): String = x match {
  case 0              => "zero"
  case 1              => "one"
  case "hello"        => "a greeting"
  case true           => "the truth"
  case List(_, _, _)  => "a 3-element list"
  case _              => "something else"
}

println(describe(0))         // zero
println(describe("hello"))   // a greeting
println(describe(List(1,2,3))) // a 3-element list

}


