using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using System.Text;

public class WebGetSomething : MonoBehaviour {

    public Text text;

	// Use this for initialization
	void Start () {
        StartCoroutine(getSomething());
        //StartCoroutine(postSomething());
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    IEnumerator getSomething()
    {
        UnityWebRequest request = UnityWebRequest.Get("https://7axd5ce1p3.execute-api.eu-west-1.amazonaws.com/test/id/1");
        yield return request.SendWebRequest();
        text.text = request.downloadHandler.text;
    }

    IEnumerator postSomething()
    {
        byte[] payload = new byte[1024];
        payload = Encoding.UTF8.GetBytes("{\"test\":\"hallo\"}");
        UnityWebRequest wr = new UnityWebRequest("http://www.google.de");
        wr.method = UnityWebRequest.kHttpVerbPOST;

        wr.useHttpContinue = false;
        wr.chunkedTransfer = false;
        wr.redirectLimit = 0;
        wr.timeout = 60;
        
        UploadHandler uploader = new UploadHandlerRaw(payload);
        
        uploader.contentType = "application/json";

        wr.uploadHandler = uploader;

        yield return wr.SendWebRequest();

        if (wr.isHttpError)
        {
            text.text = Encoding.UTF8.GetString(wr.uploadHandler.data, 0, wr.uploadHandler.data.Length);
            Debug.Log("Hat geklappt oder auch nicht");
        }
    }
}
