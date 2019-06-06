/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import junit.framework.TestCase;

/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision$
 */
public class UrlValidatorTest extends TestCase {

   private final boolean printStatus = false;
   private final boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   // Test Regular URLs
   // URLS from: https://formvalidation.io/guide/validators/uri/
   public void testIsValidStandard()
   {
      // Initialize urlVal object
      UrlValidator urlVal = UrlValidator();

      // Should Assert True
      assertTrue(urlVal.isValid("http://foo.com/blah_blah"));
      assertTrue(urlVal.isValid("http://www.example.com/wpstyle/?p=364"));
      assertTrue(urlVal.isValid("http://userid@example.com:8080"));
      assertTrue(urlVal.isValid("http://foo.bar/?q=Test%20URL-encoded%20stuff"));
      assertTrue(urlVal.isValid("http://223.255.255.254"));

      // Should Assert False
      assertFalse(urlVal.isValid("http://"));
      assertFalse(urlVal.isValid("http:///a"));
      assertFalse(urlVal.isValid("http://10.1.1.255"));
      assertFalse(urlVal.isValid("http://3628126748"));
      assertFalse(urlVal.isValid("http://.www.foo.bar./"));
   }

   // Schemes
   public void testIsValidSchemes()
   {
      // Scheme List
      String schemesList = {"https", "http"};

      // Initialize urlVal object
      UrlValidator urlVal = UrlValidator(schemesList);

      // Should Assert True
      assertTrue(urlVal.isValid("http://foo.com/blah_blah"));
      assertTrue(urlVal.isValid("http://userid@example.com"));
      assertTrue(urlVal.isValid("https://code.google.com/events/#&product=browser"));
      assertTrue(urlVal.isValid("https://foo.bar/?q=Test%20URL-encoded%20stuff"));

      // Should Assert False
      assertFalse(urlVal.isValid("htp://foo.com/blah_blah"));
      assertFalse(urlVal.isValid("htttp://userid@example.com"));
      assertFalse(urlVal.isValid("hpt://code.google.com/events/#&product=browser"));
      assertFalse(urlVal.isValid("h://foo.bar/?q=Test%20URL-encoded%20stuff"));


      // Test All Schemes
      // Initialize urlVal object
      UrlValidator urlValAll = UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);

      // Should Assert True
      assertTrue(urlValAll.isValid("http://foo.com/blah_blah"));
      assertTrue(urlValAll.isValid("http://userid@example.com"));
      assertTrue(urlValAll.isValid("https://code.google.com/events/#&product=browser"));
      assertTrue(urlValAll.isValid("https://foo.bar/?q=Test%20URL-encoded%20stuff"));

      // Should Assert False
      assertFalse(urlValAll.isValid("htp://foo.com/blah_blah"));
      assertFalse(urlValAll.isValid("htttp://userid@example.com"));
      assertFalse(urlValAll.isValid("hpt://code.google.com/events/#&product=browser"));
      assertFalse(urlValAll.isValid("h://foo.bar/?q=Test%20URL-encoded%20stuff"));
   }

   // Authorities
   public void testIsValidAuthorities()
   {
      // Initialize urlVal object
      UrlValidator urlVal = UrlValidator();

      // Should Assert True
      assertTrue(urlVal.isValid("255.255.255.255:8080"));
      assertTrue(urlVal.isValid("0.0.0.0:8080"));
      assertTrue(urlVal.isValid("127.0.0.1:8080"));
      assertTrue(urlVal.isValid("192.453.222.01:8080"));
      assertTrue(urlVal.isValid("255.254.253.252:8080"));

      // Should Assert False
      assertFalse(urlVal.isValid("255.255.255.255"));
      assertFalse(urlVal.isValid("0.0.0.0"));
      assertFalse(urlVal.isValid("127.0.0.1"));
      assertFalse(urlVal.isValid("192.453.222.01"));
      assertFalse(urlVal.isValid("255.254.253.252"));
   }

   // Ports
   public void testIsValidPorts()
   {
      // Initialize urlVal object
      UrlValidator urlVal = UrlValidator();

      // Should Assert True
      assertTrue(urlVal.isValid("255.255.255.255:8080"));
      assertTrue(urlVal.isValid("0.0.0.0:8080"));
      assertTrue(urlVal.isValid("127.0.0.1:8080"));
      assertTrue(urlVal.isValid("192.453.222.01:8080"));
      assertTrue(urlVal.isValid("255.254.253.252:8080"));

      // Should Assert False
      assertFalse(urlVal.isValid("255.255.255.255:80a0"));
      assertFalse(urlVal.isValid("0.0.0.0:-1000"));
      assertFalse(urlVal.isValid("127.0.0.1:700000"));
      assertFalse(urlVal.isValid("192.453.222.01:abcd3"));
      assertFalse(urlVal.isValid("255.254.253.252:@-304"));
   }

   // Local URLS
   public void testIsValidLocal()
   {
      // Initialize urlVal object
      UrlValidator urlVal = UrlValidator();

      // Should Assert True
      assertTrue(urlVal.isValid("http://www.google.com/index.html"));

      // Should Assert False
      assertFalse(urlVal.isValid("file:///C:/randomfile.file"));

      // List
      String list = {"http", "file"};

      // Allow Local Files
      UrlValidator urlValLocal = UrlValidator(list, UrlValidator.ALLOW_LOCAL_URLS);

      // Should Assert False
      assertTrue(urlVal.isValid("file:///C:/randomfile.file"));

   }
}
