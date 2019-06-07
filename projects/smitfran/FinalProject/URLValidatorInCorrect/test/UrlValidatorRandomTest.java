/***Random Test Cases*************/

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

import junit.framework.TestCase;

/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision$
 */
public class UrlValidatorRandomTest extends TestCase {
   
   private int RandomUrlPartsFail = 0;
   private int ConstructorZeroArguementsFail = 0;
   private int ConstructorOneArguementFail = 0;
   private int ConstructorTwoArguementFail = 0;
   
   private final boolean printStatus = false;
   private final boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorRandomTest(String testName) {
      super(testName);
   }

 
    //No arguement constructor
    public void testValidatorConstructorZeroArguements() {
    	System.out.println("**************testValidatorConstructorZeroArguements**********");
    	//Array lists to hold URL and valid/invalid pairs
    	ArrayList<String> urlsList = new ArrayList<String>();
    	ArrayList<String> validList = new ArrayList<String>();
    	
    	//Read in url values from urlList.csv
    	String fileName = "test/urlList.csv";
    	File file = new File(fileName);

    	try {
			Scanner scanIn = new Scanner(new BufferedReader(new FileReader(fileName)));
			
			while (scanIn.hasNextLine()) {
				String inputLine = scanIn.nextLine();
				
				//split by ,
				String[] csvComponents = inputLine.split(",");
				//Add corresponding part to correct ArrayList
				urlsList.add(csvComponents[0]);
				validList.add(csvComponents[1]);
		
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	
    	for (int i = 0; i < 256; i++) {
 			
 		    //Get random url index
    		Random randomUrl = new Random();
 				   
    		int randNumIdxUrl = randomUrl.nextInt(urlsList.size());

    		
    		System.out.println("TEST " + Integer.toString(i+1) + " TEST INPUT URL: " + urlsList.get(randNumIdxUrl) + " Expected isValid = " + validList.get(randNumIdxUrl));
    		if (validList.get(randNumIdxUrl).equals("TRUE")) {
    			//call assertTrue for urlValidator.isValid(url)
    			UrlValidator urlValidator = new UrlValidator();
    			if (urlValidator.isValid(urlsList.get(randNumIdxUrl))) {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST PASSED");
    			}
    			else {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST FAILED");
    				ConstructorZeroArguementsFail++;
    			}
    			assertTrue(urlValidator.isValid(urlsList.get(randNumIdxUrl)));
    		}
    		else {
      			//call assertFalse for urlValidator.isValid(url)
    			UrlValidator urlValidator = new UrlValidator();
    			if (!urlValidator.isValid(urlsList.get(randNumIdxUrl))) {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST PASSED");
    			}
    			else {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST FAILED");
    				ConstructorZeroArguementsFail++;
    			}
    			assertFalse(urlValidator.isValid(urlsList.get(randNumIdxUrl)));
    			
    		}
    		
    	}
    	if (ConstructorZeroArguementsFail > 0)
    		System.out.println("OVERALL testValidatorConstructorZeroArguements() FAILED " + Integer.toString(ConstructorZeroArguementsFail));
    }
    //One Arguement constructor, Scheme HTTP, HTTPS
    public void testValidatorConstructorOneArguement(){
    	System.out.println("**************testValidatorConstructorOneArguement**********");
    	//Array lists to hold URL and valid/invalid pairs
    	ArrayList<String> urlsList = new ArrayList<String>();
    	ArrayList<String> validList = new ArrayList<String>();
    	
    	//Read in url values from urlList.csv
    	String fileName = "test/urlList.csv";
    	File file = new File(fileName);

    	try {
			Scanner scanIn = new Scanner(new BufferedReader(new FileReader(fileName)));
			
			while (scanIn.hasNextLine()) {
				String inputLine = scanIn.nextLine();
				
				//split by ,
				String[] csvComponents = inputLine.split(",");
				//Add corresponding part to correct ArrayList
				urlsList.add(csvComponents[0]);
				validList.add(csvComponents[1]);
		
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	for (int i = 0; i < 256; i++) {
    		
 		    //Get random url index
    		Random randomUrl = new Random();
 				   
    		int randNumIdxUrl = randomUrl.nextInt(urlsList.size());
    		
    		System.out.println("TEST " + Integer.toString(i+1) + " TEST INPUT URL: " + urlsList.get(randNumIdxUrl) + " Expected isValid = " + validList.get(randNumIdxUrl));
    		if (validList.get(randNumIdxUrl).equals("TRUE")) {
    			//call assertTrue for urlValidator.isValid(url)
    			UrlValidator urlValidator = new UrlValidator(new String[] {"HTTP","HTTPS"});
    			if (urlValidator.isValid(urlsList.get(randNumIdxUrl))) {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST PASSED");
    			}
    			else {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST FAILED");
    				ConstructorOneArguementFail++;
    			}
    			assertTrue(urlValidator.isValid(urlsList.get(randNumIdxUrl)));
    		}
    		else {
      			//call assertFalse for urlValidator.isValid(url)
    			UrlValidator urlValidator = new UrlValidator(new String[] {"HTTP","HTTPS"});
    			if (!urlValidator.isValid(urlsList.get(randNumIdxUrl))) {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST PASSED");
    			}
    			else {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST FAILED");
    				ConstructorOneArguementFail++;
    			}
    			assertFalse(urlValidator.isValid(urlsList.get(randNumIdxUrl)));
    			
    		}
    		
    	}
    	if (ConstructorOneArguementFail > 0)
    		System.out.println("OVERALL testValidatorConstructorOneArguement() FAILED " + Integer.toString(ConstructorOneArguementFail));
    }
    
    //Three Arguement constructor schemes http, https, NO_FRAGMENTS
    public void testValidatorConstructorTwoArguement(){
    	System.out.println("**************testValidatorConstructorTwoArguement**********");
    	//Array lists to hold URL and valid/invalid pairs
    	ArrayList<String> urlsList = new ArrayList<String>();
    	ArrayList<String> validList = new ArrayList<String>();
    	
    	//Read in url values from urlList.csv
    	String fileName = "test/urlList.csv";
    	File file = new File(fileName);

    	try {
			Scanner scanIn = new Scanner(new BufferedReader(new FileReader(fileName)));
			
			while (scanIn.hasNextLine()) {
				String inputLine = scanIn.nextLine();
				
				//split by ,
				String[] csvComponents = inputLine.split(",");
				//Add corresponding part to correct ArrayList
				urlsList.add(csvComponents[0]);
				validList.add(csvComponents[1]);
		
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	for (int i = 0; i < 256; i++) {
    		
 		    //Get random url index
    		Random randomUrl = new Random();
 				   
    		int randNumIdxUrl = randomUrl.nextInt(urlsList.size());
    		
    		System.out.println("TEST " + Integer.toString(i+1) + " TEST INPUT URL: " + urlsList.get(randNumIdxUrl) + " Expected isValid = " + validList.get(randNumIdxUrl));
    		if (validList.get(randNumIdxUrl).equals("TRUE")) {
    			//call assertTrue for urlValidator.isValid(url)
    		    String[] schemes = {"http","https"};
    		    UrlValidator urlValidator = new UrlValidator(schemes, UrlValidator.NO_FRAGMENTS);
    			if (urlValidator.isValid(urlsList.get(randNumIdxUrl))) {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST PASSED");
    			}
    			else {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST FAILED");
    				ConstructorTwoArguementFail++;
    			}
    			assertTrue(urlValidator.isValid(urlsList.get(randNumIdxUrl)));
    		}
    		else {
      			//call assertFalse for urlValidator.isValid(url)
    		    String[] schemes = {"http","https"};
    		    UrlValidator urlValidator = new UrlValidator(schemes, UrlValidator.NO_FRAGMENTS);
    			if (!urlValidator.isValid(urlsList.get(randNumIdxUrl))) {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST PASSED");
    			}
    			else {
    				System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST FAILED");
    				ConstructorTwoArguementFail++;
    			}
    			assertFalse(urlValidator.isValid(urlsList.get(randNumIdxUrl)));
    			
    		}
    		
    	}
    	if (ConstructorTwoArguementFail > 0)
    		System.out.println("OVERALL testValidatorConstructorTwoArguement() FAILED " + Integer.toString(ConstructorTwoArguementFail));
    }  
    
    
   //-------------------- Test data for creating a composite URL
   /**
    * The data given below approximates the 4 parts of a URL
    * <scheme>://<authority><path>?<query> except that the port number
    * is broken out of authority to increase the number of permutations.
    * A complete URL is composed of a scheme+authority+port+path+query,
    * all of which must be individually valid for the entire URL to be considered
    * valid.
    */
   public void testValidatorRandomUrlParts() {
	   
	   System.out.println("***************testValidatorRandomUrlParts*************");
   	   for (int i = 0; i < 256; i++) {
		   //Random scheme**********************
		   ArrayList<String> urlScheme = new ArrayList<String>();
		   ArrayList<String> urlSchemeVal = new ArrayList<String>();
	   
		   urlScheme.add("http://");
		   urlSchemeVal.add("TRUE");
		   urlScheme.add("ftp://");
		   urlSchemeVal.add("TRUE");
		   urlScheme.add("h3t://");
		   urlSchemeVal.add("TRUE");
		   urlScheme.add("3ht://");
		   urlSchemeVal.add("FALSE");
		   
		   
		   //build test url with random scheme
		   String urlTest = "";
	
		   //Append random scheme to urlTest
		   Random randomScheme = new Random();
		   
		   int randNumIdxScheme = randomScheme.nextInt(urlScheme.size());

		   urlTest = urlTest + urlScheme.get(randNumIdxScheme);

		   
		   //Random authority*******************
		   ArrayList<String> urlAuthority = new ArrayList<String>();
		   ArrayList<String> urlAuthorityVal = new ArrayList<String>();
		   
		   urlAuthority.add("www.google.com");
		   urlAuthorityVal.add("TRUE");
		   urlAuthority.add("go.com");
		   urlAuthorityVal.add("TRUE");
		   urlAuthority.add("255.255.255.255");
		   urlAuthorityVal.add("TRUE");
		   urlAuthority.add("256.256.256.256");
		   urlAuthorityVal.add("FALSE");
		   
		   //Append random authority to urlTest
		   Random randomAuthority = new Random();
		   
		   int randNumIdxAuthority = randomAuthority.nextInt(urlAuthority.size());

		   urlTest = urlTest + urlAuthority.get(randNumIdxAuthority);
		   
		   //Random port*******************
		   ArrayList<String> urlPort = new ArrayList<String>();
		   ArrayList<String> urlPortVal = new ArrayList<String>();
		   
		   urlPort.add(":80");
		   urlPortVal.add("TRUE");
		   urlPort.add(":65535");
		   urlPortVal.add("TRUE");
		   urlPort.add(":0");
		   urlPortVal.add("TRUE");
		   urlPort.add(":-1");
		   urlPortVal.add("FALSE");
		   
		   //Append random port to urlTest
		   Random randomPort = new Random();
		   
		   int randNumIdxPort = randomPort.nextInt(urlPort.size());

		   urlTest = urlTest + urlPort.get(randNumIdxPort);
		   
		   //Random path*******************
		   ArrayList<String> urlPath = new ArrayList<String>();
		   ArrayList<String> urlPathVal = new ArrayList<String>();
		   
		   urlPath.add("/test1");
		   urlPathVal.add("TRUE");
		   urlPath.add("/t123");
		   urlPathVal.add("TRUE");
		   urlPath.add("/$23");
		   urlPathVal.add("TRUE");
		   urlPath.add("/../");
		   urlPathVal.add("FALSE");
		   
		   //Append random port to urlTest
		   Random randomPath = new Random();
		   
		   int randNumIdxPath = randomPath.nextInt(urlPath.size());

		   urlTest = urlTest + urlPath.get(randNumIdxPath);
		   
		   String expectedValidity = "";
		   if (urlSchemeVal.get(randNumIdxScheme).equals("TRUE") && urlAuthorityVal.get(randNumIdxAuthority).equals("TRUE")
				   && urlPortVal.get(randNumIdxPort).equals("TRUE") && urlPathVal.get(randNumIdxPath).equals("TRUE"))
			   expectedValidity = "TRUE";
		   else
			   expectedValidity = "FALSE";
		   
	
		   System.out.println("TEST " + Integer.toString(i+1) + " TEST INPUT URL: " + urlTest + " Expected isValid = " + expectedValidity);
		   if (expectedValidity.equals("TRUE")) {
		   //call assertTrue for urlValidator.isValid(url)
		       long options =
		               UrlValidator.ALLOW_2_SLASHES
		                   + UrlValidator.ALLOW_ALL_SCHEMES
		                   + UrlValidator.NO_FRAGMENTS;
		       UrlValidator urlValidator = new UrlValidator(null, null, options);
			   if (urlValidator.isValid(urlTest)) {
				   System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST PASSED");
			   }
			   else {
				   System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST FAILED");
				   RandomUrlPartsFail++;
			   }
			   assertTrue(urlValidator.isValid(urlTest));
		   }
		   else {
			   //call assertFalse for urlValidator.isValid(url)
		       long options =
		               UrlValidator.ALLOW_2_SLASHES
		                   + UrlValidator.ALLOW_ALL_SCHEMES
		                   + UrlValidator.NO_FRAGMENTS;
		       UrlValidator urlValidator = new UrlValidator(null, null, options);
			   if (!urlValidator.isValid(urlTest)) {
				   System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = FALSE, TEST PASSED");
			   }
			   else {
				   System.out.println("TEST# " + Integer.toString(i+1) + " Actual isValid = TRUE, TEST FAILED");
				   RandomUrlPartsFail++;
			   }
			   assertFalse(urlValidator.isValid(urlTest));
				
		   }
			
   	   }   
   	   
   	   if (RandomUrlPartsFail > 0)
   		   System.out.println("OVERALL testValidatorRandomUrlParts() FAILED " + Integer.toString(RandomUrlPartsFail));
		   
   }
   

}
