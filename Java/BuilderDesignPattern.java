/* Builder Design Pattern
 * 010515
 * 
 * http://stackoverflow.com/questions/222214/managing-constructors-with-many-parameters-in-java-1-4/222295#222295
 */

public class BuilderDesignPattern {
	static class Champion {
	  private String name;
	  private String place;
	  private String type;
	  private int number;
		
	  public Champion(String n, String p, String t, int val) {
		name = n;
		place = p;
		type = t;
		number = val;
	  }
		
	  public String toString() {
		return name + " " + place + " " + type + " " + "#" + number;
	  }
	}
	
	static class ChampionBuilder {
	  // If we leave off a required field (e.g. name is required) then we can have the Champion constructor throw an exception when a required parameter is null.
	  // Builder design pattern lets us have default/optional arguments without needing to keep track of any kind of argument order, since any order of those calls will work equally well.
	  private String _name;
	  private String _place = "NOT_SPECIFIED";
	  private String _type = "NOT_SPECIFIED";
	  private int _number = 0;
		
	  public ChampionBuilder(){}
		
	  public Champion buildChampion() {
		return new Champion(_name, _place, _type, _number);
	  }
		
	  public ChampionBuilder name(String _name) {
		this._name = _name;
		return this;
	  }
		
	  public ChampionBuilder place(String _place) {
		this._place = _place;
		return this;
	  }
	
	  public ChampionBuilder type(String _type){
		this._type = _type;
		return this;
	  }
	
	  public ChampionBuilder number(int _number) {
		this._number = _number;
		return this;
	  }
	}
	
	static public void main(String[] args) {
	  // Create a new champion and specify all the fields
	  Champion JarvanIV = new ChampionBuilder()
	      .name("JarvanIV")
		  .place("Demacia")
		  .type("Fighter")
		  .number(1)
		  .buildChampion();
		
	  // Create a new champion and specify some fields
	  Champion Nocturne = new ChampionBuilder()
	      .name("Nocturne")
		  .type("Fighter")
		  .buildChampion();
	
	  // Output each champion's information
	  System.out.println(JarvanIV);
	  System.out.println(Nocturne);
	}
}
